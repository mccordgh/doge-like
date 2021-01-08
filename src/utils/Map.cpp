//
//  Map.cpp
//  2d_game_engine
//
//  Created by Matthew mccord on 8/9/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#include <fstream>
#include <sstream>

#include "Map.h"
#include "ECS/Components.h"
#include "Game.h"
#include "libs/json.hpp"

extern EntityManager* GameManager;

using json = nlohmann::json;
using namespace std;

Map::Map(string texId, int ms) : textureId(texId), mapScale(ms)
{}

unordered_map<string, int> Map::LoadTiledJsonMap(string path)
{
    ifstream mapFile(path);
    json mapJson;
    mapFile >> mapJson;

    int tileRows = static_cast<int>(mapJson["height"].get<double>());
    int tileColumns = static_cast<int>(mapJson["width"].get<double>());

    int tileHeight = static_cast<int>(mapJson["tileheight"].get<double>());
    int tileWidth = static_cast<int>(mapJson["tilewidth"].get<double>());

    tileSize = tileWidth;
    scaledSize = mapScale * tileSize;

    int mapWidth = tileColumns * scaledSize;
    int mapHeight = tileRows * scaledSize;

    auto jsonLayers = mapJson["layers"];

    for (auto& jsonLayer : jsonLayers)
    {
        string name = jsonLayer["name"].get<string>();
        int number = static_cast<int>(jsonLayer["id"].get<double>());

        double parallaxX = NULL;
        double parallaxY = NULL;

        bool parallaxxKeyExists = jsonLayer.find("parallaxx") != jsonLayer.end();
        bool parallaxyKeyExists = jsonLayer.find("parallaxy") != jsonLayer.end();

        parallaxX = parallaxxKeyExists ? jsonLayer["parallaxx"].get<double>() : 1.0;
        parallaxY = parallaxyKeyExists ? jsonLayer["parallaxy"].get<double>() : 1.0;

        Layer* newLayer = new Layer{ name, number };

        vector<int> data = jsonLayer["data"];

        int tileY = 0;
        int tileX = 0;
        for (int i = 0; i < data.size(); ++i)
        {
            int tileX = i % tileColumns;
            bool moveToNextRow = tileX == 0 && i != 0;

            if (moveToNextRow)
            {
                tileY++;
                tileX = 0;
            }

            int tileId = data[i];

            // Tiled puts the id as 0 if no tile is present, so we need to offset by -1 so that 1 will be our first tile.
            int srcX = (tileId - 1) * tileSize;
            int srcY = 0;
            int xpos = tileX * scaledSize;
            int ypos = tileY * scaledSize;

            newLayer->AddTile(textureId, srcX, srcY, xpos, ypos, tileSize, mapScale, parallaxX, parallaxY);
        }

        layers.emplace_back(newLayer);
    }

    Entity* player = World::entityManager->addEntity();

    player->addComponent<TransformComponent>(
        800, //playerSpawnX will come from map data eventually
        800, //playerSpawnY will come from map data eventually
        CONSTANTS_STANDARD_TILE_SIZE,
        CONSTANTS_STANDARD_TILE_SIZE,
        CONSTANTS_STANDARD_TILE_SCALE
    );
    player->addComponent<SpriteComponent>("player", true);
    player->addComponent<KeyboardController>();
    player->addComponent<ColliderComponent>("player");
    player->addGroup(World::entityManager->groupPlayers);

    layers[0]->AddEntity(player);

    World::camera->centerOnEntity(player);

    return unordered_map<string, int>({ {"mapWidth", mapWidth}, {"mapHeight", mapHeight }});
}

//void Map::LoadPyxelJsonMap(string path)
//{
//    ifstream mapFile(path);
//    json mapJson;
//    mapFile >> mapJson;
//
//    int tileRows = static_cast<int>(mapJson["tileshigh"].get<double>());
//    int tileColumns = static_cast<int>(mapJson["tileswide"].get<double>());
//
//    int tileHeight = static_cast<int>(mapJson["tileheight"].get<double>());
//    int tileWidth = static_cast<int>(mapJson["tilewidth"].get<double>());
//
//    GameManager->setMapSize(tileColumns * tileWidth * scaledSize, tileRows * tileHeight * scaledSize);
//
//    auto jsonLayers = mapJson["layers"];
//
//    // remove these dummies later
//    int count = 0;
//    int layerCount = 0;
//    for (auto& jsonLayer : jsonLayers)
//    {
//        layerCount++;
//
//        string name = jsonLayer["name"].get<string>();
//        int number = static_cast<int>(jsonLayer["number"].get<double>());
//
//        Layer* newLayer = new Layer{ name, number };
//
//        for (auto& t : jsonLayer["tiles"])
//        {
//            // really dumb way to just test layer 2
//            // all first layer tiles will be the grass at 0, 0 in tilesheet
//            // all second layer tiles will be the semi transparent thing in 2, 0 tilesheet
//            if (layerCount == 1)
//            {
//                newLayer->AddTile(textureId, tileSize * count, 0, t["x"] * scaledSize, t["y"] * scaledSize, tileHeight, mapScale);
//            }
//            else
//            {
//                if (rand() % 2)
//                {
//                    newLayer->AddTile(textureId, tileSize * 2, 0, t["x"] * scaledSize, t["y"] * scaledSize, tileHeight, mapScale);
//                }
//            }
//
//            count++;
//
//            if (count > 1)
//            {
//                count = 0;
//            }
//        }
//
//        layers.emplace_back(newLayer);
//    }
//}

vector<Layer*> Map::getLayers()
{
    return layers;
}

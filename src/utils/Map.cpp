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
#include "Manager.h"
#include "libs/json.hpp"

extern Manager* GameManager;

using json = nlohmann::json;
using namespace std;


Layer::Layer() {};
Layer::~Layer() {};

Layer::Layer(string n, int num) : name(n), number(num)
{};

void Layer::AddTile(string tileSheetId, int srcX, int srcY, int xpos, int ypos, int tileSize, int mapScale, Group groupMap)
{
    Entity* tile = GameManager->addEntity();

    tile->addComponent<TileComponent>(srcX, srcY, xpos, ypos, tileSize, mapScale, tileSheetId);

    tiles.emplace_back(tile);
}

vector<Entity*> Layer::getTiles()
{
    return tiles;
}

Map::Map(string texId, int ms, int tsize) : textureId(texId), mapScale(ms), tileSize(tsize)
{
    scaledSize = ms * tsize;
}

//  JSON MAP LOADER
void Map::LoadJsonMap(string path, Group groupColliders, Group groupMap)
{
    ifstream mapFile(path);
    json mapJson;
    mapFile >> mapJson;

    int tileRows = static_cast<int>(mapJson["tileshigh"].get<double>());
    int tileColumns = static_cast<int>(mapJson["tileswide"].get<double>());

    int tileHeight = static_cast<int>(mapJson["tileheight"].get<double>());
    int tileWidth = static_cast<int>(mapJson["tilewidth"].get<double>());

    auto jsonLayers = mapJson["layers"];

    // remove these dummies later
    int count = 0;
    int layerCount = 0;
    for (auto& jsonLayer : jsonLayers)
    {
        layerCount++;

        string name = jsonLayer["name"].get<string>();
        int number = static_cast<int>(jsonLayer["number"].get<double>());

        Layer* newLayer = new Layer{ name, number };

        for (auto& t : jsonLayer["tiles"])
        {
            // really dumb way to just test layer 2
            // all first layer tiles will be the grass at 0, 0 in tilesheet
            // all second layer tiles will be the semi transparent thing in 2, 0 tilesheet
            if (layerCount == 1)
            {
                newLayer->AddTile(textureId, tileSize * count, 0, t["x"] * scaledSize, t["y"] * scaledSize, tileHeight, mapScale, groupMap);
            }
            else
            {
                if (rand() % 2)
                {
                    newLayer->AddTile(textureId, tileSize * 2, 0, t["x"] * scaledSize, t["y"] * scaledSize, tileHeight, mapScale, groupMap);
                }
            }

            count++;

            if (count > 1)
            {
                count = 0;
            }
        }

        layers.emplace_back(newLayer);
    }

    return;
}

vector<Layer*> Map::getLayers()
{
    return layers;
}

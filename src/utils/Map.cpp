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
    /*  tile->addGroup(groupMap);*/
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
    auto jsonLayer = jsonLayers[1];

    string name = jsonLayer["name"].get<string>();
    int number = static_cast<int>(jsonLayer["number"].get<double>());
    
    Layer* newLayer = new Layer{ name, number };

    for (auto& t : jsonLayer["tiles"])
    {
        // TODO: USING HEIGHT FOR THE OVERALL SIZE INSTEAD OF HEIGHT AND WIDTH
        newLayer->AddTile(textureId, 0, 0, t["x"] * scaledSize, t["y"] * scaledSize, tileHeight, mapScale, groupMap);
    }

    layers.emplace_back(newLayer);

    return;
}

vector<Layer*> Map::getLayers()
{
    return layers;
}



//void Map::AddTile(int srcX, int srcY, int xpos, int ypos, Group groupMap)
//{
//    Entity* tile = GameManager->addEntity();
//
//    tile->addComponent<TileComponent>(srcX, srcY, xpos, ypos, tileSize, mapScale, textureId);
//    tile->addGroup(groupMap);
//}


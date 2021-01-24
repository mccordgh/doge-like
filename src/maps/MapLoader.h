//
//  MapLoader.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/9/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include "Map.h"
#include "libs/json.hpp"

using json = nlohmann::json;
using namespace std;

class MapLoader
{
public:
    static void LoadTiledJsonMap(Map* map, std::string path, int scaledSize);
    static void loadMapData(Map* map, json mapJson, int scaledSize, unordered_map<int, vector<TileObject>>& tileObjectDict);
    static void loadTileData(Map* map, json mapJson, unordered_map<int, vector<TileObject>>& tileObjectDict);
};

//
//  Map.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/9/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include <string>
#include <unordered_map>
#include "ECS/ECS.h"
#include "Layer.h"
#include "worlds/World.h"

using namespace std;

class Map
{
public:
    Map(std::string texId, int ms);

    //void AddTile(int srcX, int srcY, int xpos, int ypos, Group groupMap);
    //void AddTileToLayer(int layerIndex, int srcX, int srcY, int xpos, int ypos, Group groupMap);

    //void LoadPyxelJsonMap(std::string path);
    unordered_map<string, int> LoadTiledJsonMap(std::string path);
    //void LoadMap(std::string path, Group groupColliders, Group groupMap);
    //void LoadMap(std::string path, int sizeX, int sizeY, Group groupColliders, Group groupMap);

    vector<Layer*> getLayers();

private:
    vector<Layer*> layers;
    std::string textureId;

    int mapScale;
    int tileSize;
    int scaledSize;
};

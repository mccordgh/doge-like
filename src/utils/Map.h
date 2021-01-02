//
//  Map.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/9/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include <string>
#include <map>
#include "ECS/ECS.h"

using namespace std;

class Layer
{
public:
    Layer();
    Layer(string n, int num);

    ~Layer();

    void AddTile(string tileSheetId, int srcX, int srcY, int xpos, int ypos, int tileSize, int mapScale, Group groupMap);

    string name;
    int number;

    vector<Entity*> getTiles();

private:
    vector<Entity*> tiles;
};

class Map
{
public:
    Map(std::string texId, int ms, int tsize);

    //void AddTile(int srcX, int srcY, int xpos, int ypos, Group groupMap);
    //void AddTileToLayer(int layerIndex, int srcX, int srcY, int xpos, int ypos, Group groupMap);

    void LoadJsonMap(std::string path, Group groupColliders, Group groupMap);
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

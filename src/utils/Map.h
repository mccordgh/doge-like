//
//  Map.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/9/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include <string>
#include "ECS/ECS.h"

class Map
{
public:
    Map(std::string texId, int ms, int tsize);

    void AddTile(int srcX, int srcY, int xpos, int ypos, Group groupMap);

    void LoadMap(std::string path, Group groupColliders, Group groupMap);
    //void LoadMap(std::string path, int sizeX, int sizeY, Group groupColliders, Group groupMap);

private:
    std::string textureId;

    int mapScale;
    int tileSize;
    int scaledSize;
};

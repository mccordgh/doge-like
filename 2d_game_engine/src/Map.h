//
//  Map.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/9/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once
#include <string>

class Map
{
public:
    Map(std::string texId, int ms, int tsize);
    ~Map();
    
    void AddTile(int srcX, int srcY, int xpos, int ypos);
    void LoadMap(std::string path, int sizeX, int sizeY);
    
private:
    std::string textureId;
    
    int mapScale;
    int tileSize;
    int scaledSize;
};

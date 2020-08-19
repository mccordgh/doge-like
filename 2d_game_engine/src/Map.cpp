//
//  Map.cpp
//  2d_game_engine
//
//  Created by Matthew mccord on 8/9/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#include "Map.h"
#include "Game.hpp"
#include <fstream>

Map::Map() {}

Map::~Map() {}

void Map::LoadMap(std::string path, int sizeX, int sizeY)
{
    char c;
    std::fstream mapFile;
    
    mapFile.open(path);
    
    int srcX, srcY;
    
    for(int y = 0; y < sizeY; y += 1)
    {
        for(int x = 0; x < sizeX; x += 1)
        {
            mapFile.get(c);
            srcY = atoi(&c) * 32;
            
            mapFile.get(c);
            srcX = atoi(&c) * 32;
            
            Game::AddTile(srcX, srcY, x * 64, y * 64);
            
            // ignoring comma after each tile character and newline char after each line
            mapFile.ignore();
        }
    }
    
    mapFile.close();
}

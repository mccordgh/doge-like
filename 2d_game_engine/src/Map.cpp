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
    char tile;
    std::fstream mapFile;
    
    mapFile.open(path);
    
    for(int y = 0; y < sizeY; y += 1)
    {
        for(int x = 0; x < sizeX; x += 1)
        {
            mapFile.get(tile);
            
            Game::AddTile(atoi(&tile), x * 32, y * 32);
            
            // ignoring comma after each tile character and newline char after each line
            mapFile.ignore();
        }
    }
    
    mapFile.close();
}

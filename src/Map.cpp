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
#include "ECS/ECS.h"
#include "ECS/Components.h"

extern Manager manager;

Map::Map(std::string texId, int ms, int tsize) : textureId(texId), mapScale(ms), tileSize(tsize)
{
    scaledSize = ms * tsize;
}

Map::~Map() {}

void Map::LoadMap(std::string path, int sizeX, int sizeY)
{
    char c;
    std::fstream mapFile;
    mapFile.open(path);
    
    int srcX, srcY;
    
    for (int y = 0; y < sizeY; y += 1)
    {
        for (int x = 0; x < sizeX; x += 1)
        {
            mapFile.get(c);
            srcY = atoi(&c) * tileSize;
            
            mapFile.get(c);
            srcX = atoi(&c) * tileSize;
            
            AddTile(srcX, srcY, x * scaledSize, y * scaledSize);
            
            // ignoring comma after each tile character and newline char after each line
            mapFile.ignore();
        }
    }
    
    // ignore blank line between tiles and colliders
    mapFile.ignore();
    
    for (int y = 0; y < sizeY; y += 1)
    {
        for (int x = 0; x < sizeX; x += 1)
        {
            mapFile.get(c);
            
            // 1 is collider 0 is nothing
            if (c == '1')
            {
                auto& tcol(manager.addEntity());
                tcol.addComponent<ColliderComponent>("terrain", x * scaledSize, y * scaledSize, scaledSize);
                tcol.addGroup(Game::groupColliders);
            }
            
            // ignoring comma after each tile character and newline char after each line
            mapFile.ignore();
        }
    }
    
    mapFile.close();
}

void Map::AddTile(int srcX, int srcY, int xpos, int ypos)
{
    auto& tile(manager.addEntity());

    tile.addComponent<TileComponent>(srcX, srcY, xpos, ypos, tileSize, mapScale, textureId);
    tile.addGroup(Game::groupMap);
}

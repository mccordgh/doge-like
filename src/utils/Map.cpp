//
//  Map.cpp
//  2d_game_engine
//
//  Created by Matthew mccord on 8/9/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#include <fstream>

#include "Map.h"
#include "ECS/Components.h"
#include "Manager.h"

extern Manager* GameManager;

Map::Map(std::string texId, int ms, int tsize) : textureId(texId), mapScale(ms), tileSize(tsize)
{
    scaledSize = ms * tsize;
}

void Map::LoadMap(std::string path, int sizeX, int sizeY, Group groupColliders, Group groupMap)
{
    char c;
    std::fstream mapFile;
    mapFile.open(path);

    // int srcX, srcY;
    int tileNum;

    for (int y = 0; y < sizeY; y += 1)
    {
        for (int x = 0; x < sizeX; x += 1)
        {
            mapFile.get(c);
            tileNum = atoi(&c) * tileSize;
            // mapFile.get(c);
            // srcY = atoi(&c) * tileSize;

            // mapFile.get(c);
            // srcX = atoi(&c) * tileSize;

            // AddTile(srcX, srcY, x * scaledSize, y * scaledSize);

            // All tiles are just in a straight line so x/y is 0 for now
            AddTile(tileNum, 0, x * scaledSize, y * scaledSize, groupMap);

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
                Entity* tcol = GameManager->addEntity();

                tcol->addComponent<ColliderComponent>("terrain", x * scaledSize, y * scaledSize, scaledSize);
                tcol->addGroup(groupColliders);
            }

            // ignoring comma after each tile character and newline char after each line
            mapFile.ignore();
        }
    }

    mapFile.close();
}

void Map::AddTile(int srcX, int srcY, int xpos, int ypos, Group groupMap)
{
    Entity* tile = GameManager->addEntity();

    tile->addComponent<TileComponent>(srcX, srcY, xpos, ypos, tileSize, mapScale, textureId);
    tile->addGroup(groupMap);
}
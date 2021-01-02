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

extern Manager* GameManager;

Map::Map(std::string texId, int ms, int tsize) : textureId(texId), mapScale(ms), tileSize(tsize)
{
    scaledSize = ms * tsize;
}

void Map::LoadMap(std::string path, Group groupColliders, Group groupMap)
{
    //fstream mapFile(path);
    std::ifstream mapFile(path);

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(mapFile, line))
    {
        lines.push_back(line);
    }

    // "tileswide " length is 10
    int tileswide = std::stoi(lines[0].substr(10, 10 - lines[0].length()));

    // "tileshigh " length is 10
    int tileshigh = std::stoi(lines[1].substr(10, 10 - lines[1].length()));

    // "tilewidth " length is 10
    int tilewidth = std::stoi(lines[2].substr(10, 10 - lines[2].length()));

    // "tileheight " length is 11
    int tileheight = std::stoi(lines[3].substr(11, 11 - lines[3].length()));

    // rename later and refactor
    std::vector<int> layerZero;

    int lastTileRow = tileshigh + 6;
    // skipping 4 because its a blank line
    // skipping 5 because it just says "layer 0"
    for (int y = 6; y < lastTileRow; ++y)
    {
        std::stringstream stream(lines[y]);

        for (int x = 0; x < tileswide; ++x)
        {
            std::string tileId;
            std::getline(stream, tileId, ',');
            layerZero.push_back(std::stoi(tileId));
        }
    }

    return;
}

//void Map::LoadMap(std::string path, int sizeX, int sizeY, Group groupColliders, Group groupMap)
//{
//    char c;
//    std::fstream mapFile;
//    mapFile.open(path);
//
//    // int srcX, srcY;
//    int tileNum;
//
//    for (int y = 0; y < sizeY; y += 1)
//    {
//        for (int x = 0; x < sizeX; x += 1)
//        {
//            mapFile.get(c);
//            tileNum = atoi(&c) * tileSize;
//            // mapFile.get(c);
//            // srcY = atoi(&c) * tileSize;
//
//            // mapFile.get(c);
//            // srcX = atoi(&c) * tileSize;
//
//            // AddTile(srcX, srcY, x * scaledSize, y * scaledSize);
//
//            // All tiles are just in a straight line so x/y is 0 for now
//            AddTile(tileNum, 0, x * scaledSize, y * scaledSize, groupMap);
//
//            // ignoring comma after each tile character and newline char after each line
//            mapFile.ignore();
//        }
//    }
//
//    // ignore blank line between tiles and colliders
//    mapFile.ignore();
//
//    for (int y = 0; y < sizeY; y += 1)
//    {
//        for (int x = 0; x < sizeX; x += 1)
//        {
//            mapFile.get(c);
//
//            // 1 is collider 0 is nothing
//            if (c == '1')
//            {
//                Entity* tcol = GameManager->addEntity();
//
//                tcol->addComponent<ColliderComponent>("terrain", x * scaledSize, y * scaledSize, scaledSize);
//                tcol->addGroup(groupColliders);
//            }
//
//            // ignoring comma after each tile character and newline char after each line
//            mapFile.ignore();
//        }
//    }
//
//    mapFile.close();
//}

void Map::AddTile(int srcX, int srcY, int xpos, int ypos, Group groupMap)
{
    Entity* tile = GameManager->addEntity();

    tile->addComponent<TileComponent>(srcX, srcY, xpos, ypos, tileSize, mapScale, textureId);
    tile->addGroup(groupMap);
}

//
//  MapLoader.cpp
//  2d_game_engine
//
//  Created by Matthew mccord on 8/9/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#include <fstream>
#include <sstream>
#include <unordered_map>

#include "MapLoader.h"
#include "ECS/Components.h"
#include "layers/ObjectLayer.h"
#include "layers/TileLayer.h"
#include "worlds/World.h"
#include "tiles/TileSheet.h"
#include "tiles/TileObject.h"

extern EntityManager* GameManager;

void MapLoader::LoadTiledJsonMap(Map* map, string path, int scaledSize)
{
    unordered_map<int, vector<TileObject>> tileObjectDict;

    ifstream mapFile(path);
    json mapJson;
    mapFile >> mapJson;

    map->nextLayerId = static_cast<int>(mapJson["nextlayerid"].get<double>());
    map->nextObjectId = static_cast<int>(mapJson["nextobjectid"].get<double>());
    map->tileHeight = static_cast<int>(mapJson["tileheight"].get<double>()) * scaledSize;
    map->tileWidth = static_cast<int>(mapJson["tileheight"].get<double>()) * scaledSize;
    map->type = mapJson["type"].get<string>();
    map->height = static_cast<int>(mapJson["height"].get<double>()) * map->tileHeight * scaledSize;
    map->width = static_cast<int>(mapJson["width"].get<double>()) * map->tileWidth * scaledSize;

    // Loading in all the data for the tilesets for later use when creating Tile entities below
    for (auto& set : mapJson["tilesets"])
    {
       /* World::assets->AddTexture("Clouds", "assets/tiles/some_clouds.png");
        World::assets->AddTexture("Tiles", "assets/tiles/tmw_desert.png");*/

        // Tileset is part of the map json data it contains the first tile id in the set, and the path to the tile json data source
        TileSet tileSet;
        tileSet.firstId = static_cast<int>(set["firstgid"].get<double>());

        string source = set["source"].get<string>();
        ifstream tileFile("assets/tiles/" + source);
        json tileJson;
        tileFile >> tileJson;

        TileSheet tileSheet;
        tileSheet.imagePath = tileJson["image"].get<string>();
        tileSheet.imageHeight = static_cast<int>(tileJson["imageheight"].get<double>());
        tileSheet.imageWidth = static_cast<int>(tileJson["imagewidth"].get<double>());
        tileSheet.name = tileJson["name"].get<string>();
        tileSheet.tileCount = static_cast<int>(tileJson["tilecount"].get<double>());
        tileSheet.tileHeight = static_cast<int>(tileJson["tileheight"].get<double>());
        tileSheet.tilesWidth = static_cast<int>(tileJson["tilewidth"].get<double>());
        tileSheet.type = tileJson["type"].get<string>();

        // Some tilesheets may not have tile object data.
        if (tileJson.find("tiles") != tileJson.end())
        {
            for (auto& tile : tileJson["tiles"])
            {
                TileWithObjects tileWithObj;
                tileWithObj.id = static_cast<int>(tile["id"].get<double>());

                json objGroup = tile["objectgroup"];

                TileObjectGroup tileObjGroup;
                tileObjGroup.id = static_cast<int>(objGroup["id"].get<double>());
                tileObjGroup.opacity = objGroup["opacity"].get<double>();
                tileObjGroup.x = static_cast<int>(objGroup["x"].get<double>());
                tileObjGroup.y = static_cast<int>(objGroup["y"].get<double>());
                tileObjGroup.visible = objGroup["visible"].get<bool>();

                //vector<TileObject> tileObjArray;
                for (auto& obj : objGroup["objects"])
                {
                    TileObject tileObj;
                    tileObj.height = static_cast<int>(obj["height"].get<double>());
                    tileObj.id = static_cast<int>(obj["id"].get<double>());
                    tileObj.type = obj["type"].get<string>();
                    tileObj.visible = obj["visible"].get<bool>();
                    tileObj.width = static_cast<int>(obj["width"].get<double>());
                    tileObj.x = static_cast<int>(obj["x"].get<double>());
                    tileObj.y = static_cast<int>(obj["y"].get<double>());

                    tileObjGroup.objects.emplace_back(tileObj);

                    // check if key exists yet for this tile id
                    if (tileObjectDict.find(tileObj.id) != tileObjectDict.end())
                    {
                        tileObjectDict[tileObj.id].emplace_back(tileObj);
                    }
                    else
                    {
                        vector<TileObject> tileObjVector;
                        tileObjVector.emplace_back(tileObj);

                        tileObjectDict.insert({ tileObj.id, tileObjVector });
                    }
                }

                tileWithObj.objectGroup = tileObjGroup;
                tileSheet.tiles.emplace_back(tileWithObj);
            }
        }

        tileSet.tileSheet = tileSheet;
        map->tileSets.emplace_back(tileSet);
    }

    // First "layers" key is layer groups which we will create a single Layer out of combining all layers in the group and creating entities from each object/tile
    for (auto& group : mapJson["layers"])
    {
        LayerGroup layerGroup;
        layerGroup.id = static_cast<int>(group["id"].get<double>());
        layerGroup.name = group["name"].get<string>();
        layerGroup.opacity = group["opacity"].get<double>();
        layerGroup.type = group["type"].get<string>();
        layerGroup.visible = group["visible"].get<bool>();
        layerGroup.x = static_cast<int>(group["x"].get<double>());
        layerGroup.y = static_cast<int>(group["y"].get<double>());

        // "layers" key here will be actual layers of type "objectgroup" or "tilelayer" (other possiblities we arent using yet as well come from Tiled)
        for (auto& layerJson : group["layers"])
        {
            string type = layerJson["type"].get<string>();

            if (type == "objectgroup")
            {
                ObjectLayer newLayer;
                newLayer.id = static_cast<int>(layerJson["id"].get<double>());
                newLayer.name = layerJson["name"].get<string>();
                newLayer.opacity = layerJson["opacity"].get<double>();
                newLayer.type = type;
                newLayer.visible = layerJson["visible"].get<bool>();
                newLayer.x = static_cast<int>(layerJson["x"].get<double>());
                newLayer.y = static_cast<int>(layerJson["y"].get<double>());

                // "objects" key will be converted to in game entities
                for (auto& obj : layerJson["objects"])
                {
                    string type = obj["type"].get<string>();
                    int xpos = static_cast<int>(obj["x"].get<double>());
                    int ypos = static_cast<int>(obj["y"].get<double>());
                    int width = static_cast<int>(obj["width"].get<double>());
                    int height = static_cast<int>(obj["height"].get<double>());

                    newLayer.AddEntity(type, xpos, ypos, width, height, scaledSize);
                }

                layerGroup.objectLayers.emplace_back(newLayer);
            }
            else if (type == "tilelayer")
            {
                TileLayer newLayer;
                newLayer.height = static_cast<int>(layerJson["height"].get<double>());
                newLayer.id = static_cast<int>(layerJson["id"].get<double>());
                newLayer.name = layerJson["name"].get<string>();
                newLayer.opacity = layerJson["opacity"].get<double>();
                newLayer.type = type;
                newLayer.visible = layerJson["visible"].get<bool>();
                newLayer.width = static_cast<int>(layerJson["width"].get<double>());
                newLayer.x = static_cast<int>(layerJson["x"].get<double>());
                newLayer.y = static_cast<int>(layerJson["y"].get<double>());

                // "data" key aka tiles property will be converted to in game tile entities
                for (auto& tileId : layerJson["data"])
                {
                    //srcX, srcY, xpos, ypos, tileSize, mapScale* parallax, tileSheetId, parallax

                    // Each tile id in this array is increased by 1 for some reason (starts at 1 instead of 0 like it does in the tileset data)
                    // so we have to compensate oof.
                    int id = tileId - 1;

                    int srcX = id * map->tileWidth;
                    int srcY = id * map->tileHeight;

                    // Hardcoded "Tiles" tile sheet id remove later in favor of more dynamic solution
                    //newLayer.AddTile("Tiles", ); // Need to figure out which tilesheetId to pass in depending on the tiles id it could be on one of multiple sheets.
                }

                layerGroup.tileLayers.emplace_back(newLayer);
            }
            else
            {
                throw std::runtime_error(string("Group's Layer is of unrecognized type: ") + type);
            }
        }

        map->layerGroups.emplace_back(layerGroup);
    }

    //int tileRows = static_cast<int>(mapJson["height"].get<double>());
    //int tileColumns = static_cast<int>(mapJson["width"].get<double>());

    //int tileHeight = static_cast<int>(mapJson["tileheight"].get<double>());
    //int tileWidth = static_cast<int>(mapJson["tilewidth"].get<double>());

    //int mapWidth = tileColumns * scaledSize;
    //int mapHeight = tileRows * scaledSize;

    //auto jsonLayers = mapJson["layers"];

    //for (auto& jsonLayer : jsonLayers)
    //{
    //    string name = jsonLayer["name"].get<string>();
    //    int number = static_cast<int>(jsonLayer["id"].get<double>());

    //    double parallax = NULL;

    //    bool parallaxxKeyExists = jsonLayer.find("parallaxx") != jsonLayer.end();
    //    bool parallaxyKeyExists = jsonLayer.find("parallaxy") != jsonLayer.end();

    //    parallax = parallaxxKeyExists ? jsonLayer["parallaxx"].get<double>() : 1.0;

    //    Layer* newLayer = new Layer{ name, number, parallax };

    //    vector<int> data = jsonLayer["data"];

    //    int tileY = 0;
    //    int tileX = 0;
    //    for (int i = 0; i < data.size(); ++i)
    //    {
    //        int tileX = i % tileColumns;
    //        bool moveToNextRow = tileX == 0 && i != 0;

    //        if (moveToNextRow)
    //        {
    //            tileY++;
    //            tileX = 0;
    //        }

    //        int tileId = data[i];

    //        // Tiled puts the id as 0 if no tile is present, so we need to offset by -1 so that 1 will be our first tile.
    //        int srcX = (tileId - 1) * tileSize;
    //        int srcY = 0;
    //        int xpos = tileX * scaledSize;
    //        int ypos = tileY * scaledSize;

    //        newLayer->AddTile(textureId, srcX, srcY, xpos, ypos, tileSize, mapScale, parallax);
    //    }

    //    layers.emplace_back(newLayer);
    //}

    //Entity* player = World::entityManager->addEntity();

    //player->addComponent<TransformComponent>(
    //    800, //playerSpawnX will come from map data eventually
    //    800, //playerSpawnY will come from map data eventually
    //    CONSTANTS_STANDARD_TILE_SIZE,
    //    CONSTANTS_STANDARD_TILE_SIZE,
    //    CONSTANTS_STANDARD_TILE_SCALE
    //    );
    //player->addComponent<SpriteComponent>("player", true);
    //player->addComponent<KeyboardController>();
    //player->addComponent<ColliderComponent>("player");
    //player->addGroup(World::entityManager->groupPlayers);

    //layers[0]->AddEntity(player, mapScale * layers[0]->getScale());

    //World::camera->centerOnEntity(player);

    //return unordered_map<string, int>({ {"mapWidth", mapWidth}, {"mapHeight", mapHeight } });
}

//void MapLoader::LoadPyxelJsonMap(string path)
//{
//    ifstream mapFile(path);
//    json mapJson;
//    mapFile >> mapJson;
//
//    int tileRows = static_cast<int>(mapJson["tileshigh"].get<double>());
//    int tileColumns = static_cast<int>(mapJson["tileswide"].get<double>());
//
//    int tileHeight = static_cast<int>(mapJson["tileheight"].get<double>());
//    int tileWidth = static_cast<int>(mapJson["tilewidth"].get<double>());
//
//    GameManager->setMapSize(tileColumns * tileWidth * scaledSize, tileRows * tileHeight * scaledSize);
//
//    auto jsonLayers = mapJson["layers"];
//
//    // remove these dummies later
//    int count = 0;
//    int layerCount = 0;
//    for (auto& jsonLayer : jsonLayers)
//    {
//        layerCount++;
//
//        string name = jsonLayer["name"].get<string>();
//        int number = static_cast<int>(jsonLayer["number"].get<double>());
//
//        Layer* newLayer = new Layer{ name, number };
//
//        for (auto& t : jsonLayer["tiles"])
//        {
//            // really dumb way to just test layer 2
//            // all first layer tiles will be the grass at 0, 0 in tilesheet
//            // all second layer tiles will be the semi transparent thing in 2, 0 tilesheet
//            if (layerCount == 1)
//            {
//                newLayer->AddTile(textureId, tileSize * count, 0, t["x"] * scaledSize, t["y"] * scaledSize, tileHeight, mapScale);
//            }
//            else
//            {
//                if (rand() % 2)
//                {
//                    newLayer->AddTile(textureId, tileSize * 2, 0, t["x"] * scaledSize, t["y"] * scaledSize, tileHeight, mapScale);
//                }
//            }
//
//            count++;
//
//            if (count > 1)
//            {
//                count = 0;
//            }
//        }
//
//        layers.emplace_back(newLayer);
//    }
//}

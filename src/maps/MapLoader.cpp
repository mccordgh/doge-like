//
//  MapLoader.cpp
//  2d_game_engine
//
//  Created by Matthew mccord on 8/9/20.
//  Copyright � 2020 MCCORDINATOR. All rights reserved.
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
#include "utils/StringHelper.h"

extern EntityManager* GameManager;

void MapLoader::LoadTiledJsonMap(Map* map, string path, int scaledSize)
{
    unordered_map<int, vector<TileObject>> tileObjectDict;

    ifstream mapFile(path);

    if (!mapFile.is_open()) {
        string errorMsg = std::string("File does not exist at: ") + path;
        throw std::runtime_error(string(errorMsg));
    }

    json mapJson;
    mapFile >> mapJson;

    map->nextLayerId = static_cast<int>(mapJson["nextlayerid"].get<double>());
    map->nextObjectId = static_cast<int>(mapJson["nextobjectid"].get<double>());
    //map->tileHeight = static_cast<int>(mapJson["tileheight"].get<double>()) * scaledSize;
    //map->tileWidth = static_cast<int>(mapJson["tileheight"].get<double>()) * scaledSize;
    map->tileHeight = static_cast<int>(mapJson["tileheight"].get<double>());
    map->tileWidth = static_cast<int>(mapJson["tileheight"].get<double>());
    map->type = mapJson["type"].get<string>();
 /*   map->height = static_cast<int>(mapJson["height"].get<double>()) * map->tileHeight * scaledSize;
    map->width = static_cast<int>(mapJson["width"].get<double>()) * map->tileWidth * scaledSize;*/
    map->tilesHigh = static_cast<int>(mapJson["height"].get<double>());
    map->tilesWide = static_cast<int>(mapJson["width"].get<double>());
    map->height = map->tilesHigh * map->tileHeight;
    map->width = map->tilesWide * map->tileWidth;

    loadTileData(map, mapJson, tileObjectDict);

    loadMapData(map, mapJson, scaledSize, tileObjectDict);
}

void MapLoader::loadTileData(Map* map, json mapJson, unordered_map<int, vector<TileObject>>& tileObjectDict)
{
    // Loading in all the data for the tilesets for later use when creating Tile entities below
    vector<json> tilesets = mapJson["tilesets"].get<vector<json>>();
    for (vector<json>::reverse_iterator it = tilesets.rbegin(); it != tilesets.rend(); ++it)
    {
        json set = *it;

         // Tileset is part of the map json data it contains the first tile id in the set, and the path to the tile json data source
        TileSet tileSet;

        // Each tile id in this array is increased by 1 for some reason (starts at 1 instead of 0 like it does in the tileset data)
        // so we have to compensate.... >:(
        tileSet.firstId = static_cast<int>(set["firstgid"].get<double>()) - 1;

        // if this is the first item while running through reverse iteration of tilesets set lastId to -1 otherwise set it to the previous items firstId - 1
        tileSet.lastId = map->tileSets.empty() ? -1 : map->tileSets.end()[-1].firstId - 1;

        string source = set["source"].get<string>();
        ifstream tileFile("assets/tiles/" + source);
        json tileJson;
        tileFile >> tileJson;

        TileSheet tileSheet;
        tileSheet.imageName = tileJson["image"].get<string>();
        tileSheet.imageHeight = static_cast<int>(tileJson["imageheight"].get<double>());
        tileSheet.imageWidth = static_cast<int>(tileJson["imagewidth"].get<double>());
        tileSheet.name = tileJson["name"].get<string>();
        tileSheet.tileCount = static_cast<int>(tileJson["tilecount"].get<double>());
        tileSheet.tileHeight = static_cast<int>(tileJson["tileheight"].get<double>());
        tileSheet.tileWidth = static_cast<int>(tileJson["tilewidth"].get<double>());
        tileSheet.tilesHigh = tileSheet.imageHeight / tileSheet.tileHeight;
        tileSheet.tilesWide = tileSheet.imageWidth / tileSheet.tileWidth;
        tileSheet.type = tileJson["type"].get<string>();

        tileSheet.textureId = StringHelper::getSubStringBeforeCharacter(tileSheet.imageName, '.');
        string imagePath = string("assets/tiles/") + tileSheet.imageName;
        World::assets->AddTexture(tileSheet.textureId, imagePath);

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
                    if (tileObjectDict.find(tileWithObj.id) != tileObjectDict.end())
                    {
                        tileObjectDict[tileWithObj.id].emplace_back(tileObj);
                    }
                    else
                    {
                        vector<TileObject> tileObjVector;
                        tileObjVector.emplace_back(tileObj);

                        tileObjectDict.insert({ tileWithObj.id, tileObjVector });
                    }
                }

                tileWithObj.objectGroup = tileObjGroup;
                tileSheet.tiles.emplace_back(tileWithObj);
            }
        }

        tileSet.tileSheet = tileSheet;
        map->tileSets.emplace_back(tileSet);
    }
}

void MapLoader::loadMapData(Map* map, json mapJson, int scaledSize, unordered_map<int, vector<TileObject>>& tileObjectDict)
{
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
        layerGroup.parallaxX = group.find("parallaxx") == group.end() ? 1.00 : group["parallaxx"].get<double>();
        //layerGroup.parallaxX = 1.00;

        // "layers" key here will be actual layers of type "objectgroup" or "tilelayer" (other possiblities we arent using yet as well can come from Tiled)
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

                    //newLayer.AddEntity(type, xpos, ypos, width, height, scaledSize);
                    // TODO Use scaled size again instead of hardcoded 1?
                    // For now just using parallaxX as we dont plan on having different x and y parallax values
                    newLayer.AddEntity(type, xpos, ypos, width, height, 1, layerGroup.parallaxX);
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

                int tileCount = 0;
                int tileRow = 0;
               /* int tileSheetCount = 0;
                int tileSheetRow = 0;*/
                // "data" key aka tiles property will be converted to in game tile entities
                for (int const item : layerJson["data"])
                {
                    // no tile exists here
                    if (item == 0)
                    {
                        tileCount++;

                        if (tileCount % map->tilesWide == 0)
                        {
                            tileRow++;
                        }
                        continue;
                    }

                    // Each tile id in this array is increased by 1 for some reason (starts at 1 instead of 0 like it does in the tileset data)
                    // so we have to compensate.... >:(
                    int id = item - 1;

                    auto it = find_if(
                        map->tileSets.rbegin(),
                        map->tileSets.rend(),
                        [&id](const TileSet& tileset)
                        {
                            // if lastId is -1 then this is the final tileset so it will have had a lastId of -1 assigned to it
                            bool partOfLastTileSet = tileset.lastId == -1 && id >= tileset.firstId;

                            return partOfLastTileSet
                                ? true
                                : id >= tileset.firstId && id <= tileset.lastId;
                        }
                    );

                    if (it == map->tileSets.rend())
                    {
                        throw runtime_error(string("no tileset found with id range"));
                    }

                    TileSet set = *it;

                    // if this is true then we need to offset the id to correctly work with another tilesheet
                    // Example: ID 49 may actually refer to the first tile in a second, third, or later tilesheet in which case id needs to offset back to 0 for the first tile
                    // If firstId is > 0 then we are on a tilesheet after the first tilesheet
                    if (set.firstId > 0)
                    {
                        id -= set.firstId;
                    }

                    int srcX = (id % set.tileSheet.tilesWide) * set.tileSheet.tileWidth;
                    int srcY = id == 0 ? 0 : (id / set.tileSheet.tilesWide) * set.tileSheet.tileHeight;

                   /* tileSheetCount++;

                    if (tileSheetCount % set.tileSheet.tilesWide == 0)
                    {
                        tileSheetRow++;
                    }*/

                    int xpos = (tileCount % map->tilesWide) * map->tileWidth;
                    int ypos = (tileRow % map->tilesHigh) * map->tileHeight;

                    // ONCE AGAIN ASSUMING TILES HAVE EQUAL WIDTH AND HEIGHT HERE PASSING IN TILESIZE
                    // ALSO TODO: Use scaled size again instead of hardcoded 1?
                    // For now just using parallaxX as we dont plan on having different x and y parallax values
                    newLayer.AddTile(set.tileSheet.textureId, srcX, srcY, xpos, ypos, map->tileHeight, 1, layerGroup.parallaxX);

                    tileCount++;

                    if (tileCount % map->tilesWide == 0)
                    {
                        tileRow++;
                    }
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
}


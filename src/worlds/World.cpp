#include "World.h"
#include "utils/Vector2D.h"
#include "ECS/Components.h"
#include "utils/Collision.h"
#include "maps/Map.h"
#include "gfx/AssetManager.h"
#include "Camera.h"
#include "maps/MapLoader.h"
#include "maps/layers/TileLayer.h"
#include "maps/layers/ObjectLayer.h"

AssetManager* World::assets = nullptr;
Camera* World::camera = nullptr;
EntityManager* World::entityManager = nullptr;
Map* World::map = nullptr;

int World::nextPlayerSpawnX = 0;
int World::nextPlayerSpawnY = 0;


World::World(SDL_Renderer* rend): renderer(rend) {
    entityManager = new EntityManager();
    assets = new AssetManager();
    camera = new Camera(0, 0, CONSTANTS_GAME_WINDOW_WIDTH, CONSTANTS_GAME_WINDOW_HEIGHT);

    map = nullptr;
};

World::~World() {};

void World::init()
{
    //assets->AddTexture("Tiles", "assets/tiles/grass_and_wall_with_borders.png");

    assets->AddTexture("Player", "assets/32x32_ff_adventure_knight.png");
    assets->AddTexture("Trigger", "assets/32x32_trigger.png");

    map = new Map();
    MapLoader::LoadTiledJsonMap(map, "assets/maps/tmw_desert_map.json", 1);

    Entity* player = entityManager->getGroup(entityManager->groupPlayers)[0];
    camera->centerOnEntity(player);
}

void World::update()
{
    entityManager->refresh();

    for (LayerGroup group : map->layerGroups)
    {
        for (TileLayer layer : group.tileLayers)
        {
            for (Entity* tile : layer.tiles)
            {
                tile->update();
            }
        }

        for (ObjectLayer layer : group.objectLayers)
        {
            for (Entity* entity : layer.entities)
            {
                entity->update();
            }
        }
    }

    camera->update();
};

void World::draw()
{
   // clear renderer
    SDL_RenderClear(renderer);

    for (LayerGroup group : map->layerGroups)
    {
        //if (group.name != "Sky") continue;
        if (group.visible)
        {
            for (TileLayer layer : group.tileLayers)
            {
                if (layer.visible)
                {
                    for (Entity* tile : layer.tiles)
                    {
                        tile->draw();
                    }
                }
            }

            for (ObjectLayer layer : group.objectLayers)
            {
                for (Entity* entity : layer.entities)
                {
                    entity->draw();
                }
            }
        }
    }

    // present everything
    SDL_RenderPresent(renderer);
};

EntityManager* World::getEntityManager()
{
    return entityManager;
}

//void World::setMapSize(int width, int height)
//{
//    currentMapWidth = width;
//    currentMapHeight = height;
//}

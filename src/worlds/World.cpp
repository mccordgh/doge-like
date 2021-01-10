#include "World.h"
#include "utils/Vector2D.h"
#include "ECS/Components.h"
#include "utils/Collision.h"
#include "utils/Map.h"
#include "gfx/AssetManager.h"
#include "Camera.h"

int World::mapWidth = 0;
int World::mapHeight = 0;

AssetManager* World::assets = nullptr;
Camera* World::camera = nullptr;
EntityManager* World::entityManager = nullptr;

World::World(SDL_Renderer* rend): renderer(rend) {
    entityManager = new EntityManager();
    assets = new AssetManager();
    camera = new Camera(0, 0, CONSTANTS_GAME_WINDOW_WIDTH, CONSTANTS_GAME_WINDOW_HEIGHT);
};

World::~World() {};

void World::init()
{
    //World::assets->AddTexture("terrain", "assets/tiles/grass_and_wall.png");
    assets->AddTexture("terrain", "assets/tiles/grass_and_wall_with_borders.png");
    assets->AddTexture("clouds", "assets/tiles/some_clouds.png");
    assets->AddTexture("desert", "assets/tiles/tmw_desert.png");
    //World::assets->AddTexture("terrain", "assets/tiles/testing_tiles_draw_and_dont_overlap.png");

    assets->AddTexture("player", "assets/ff_adventure_knight.png");

//    assets->AddTexture("projectile", "assets/projectile_test.png");

    Map* map = new Map("terrain", CONSTANTS_STANDARD_MAP_SCALE);
    //map->LoadPyxelJsonMap("assets/tiles/test_exported_load_map.json", groupColliders, groupMap);
    //unordered_map<string, int> mapDimensions = map->LoadTiledJsonMap("assets/tiles/tiled_test.json");
    unordered_map<string, int> mapDimensions = map->LoadTiledJsonMap("assets/tiles/tiled-desert-test-32x32.json");

    mapHeight = mapDimensions["mapHeight"];
    mapWidth = mapDimensions["mapWidth"];

    layers = map->getLayers();

    //Entity* player = entityManager->addEntity();

    //player->addComponent<TransformComponent>(
    //    playerSpawnX,
    //    playerSpawnY,
    //    CONSTANTS_STANDARD_TILE_SIZE,
    //    CONSTANTS_STANDARD_TILE_SIZE,
    //    CONSTANTS_STANDARD_TILE_SCALE
    //);
    //player->addComponent<SpriteComponent>("player", true);
    //player->addComponent<KeyboardController>();
    //player->addComponent<ColliderComponent>("player");
    //player->addGroup(groupPlayers);

   /* colliders = entityManager->getGroup(groupColliders);
    enemies = entityManager->getGroup(groupEnemies);
    players = entityManager->getGroup(groupPlayers);
    projectiles = entityManager->getGroup(groupProjectiles);*/

  //    World::assets->CreateProjectile("projectile", Vector2D(350, 1100), Vector2D(2, 0), 200, 2);
}

void World::update()
{
    entityManager->refresh();

    for (Layer* layer : layers)
    {
        for (auto& tile : layer->getTiles())
        {
            tile->update();
        }

   /*     for (auto& c : layer->getColliders())
        {
            c->update();
        }*/

        for (auto& e : layer->getEntities())
        {
            Vector2D ePos = e->getComponent<TransformComponent>().position;

            e->update();

            if (e->hasComponent<TransformComponent>() && e->hasComponent<ColliderComponent>())
            {
                SDL_Rect eCollider = e->getComponent<ColliderComponent>().collider;

                for (auto& c : entityManager->getGroup(entityManager->groupColliders))
                {
                    SDL_Rect cCollider = c->getComponent<ColliderComponent>().collider;

                    if (Collision::AABB(cCollider, eCollider))
                    {
                        e->getComponent<TransformComponent>().position = ePos;
                    }
                }
            }
        }
    }

    //for(auto& p : projectiles)
    //{
    //    if (Collision::AABB(player->getComponent<ColliderComponent>().collider, p->getComponent<ColliderComponent>().collider))
    //    {
    //        // std::cout << "Project HIT PLAYER ~DESTROYED" << std::endl;
    //        p->destroy();
    //    }
    //}

    camera->update();
};

void World::draw()
{
   // clear renderer
    SDL_RenderClear(renderer);

    for (Layer* layer : layers)
    {
        for (auto& tile : layer->getTiles())
        {
            tile->draw();
        }

      /*  for (auto& c : layer->getColliders())
        {
            c->draw();
        }

        for (auto& e : layer->getEnemies())
        {
            e->draw();
        }*/

        for (auto& e : layer->getEntities())
        {
            e->draw();
        }

        // We can bring this back if we have more than one player entity in game
       /* for (auto& p : layer->getPlayers())
        {
            p->draw();
        }*/
        //layer->getPlayer()->draw();

        // Bring this back when projectiles are re-introduced
        /*for (auto& p : layer->getProjectiles())
        {
            p->draw();
        }*/
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

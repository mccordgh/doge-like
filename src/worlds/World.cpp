#include "World.h"
#include "utils/Vector2D.h"
#include "ECS/Components.h"
#include "utils/Collision.h"
#include "utils/Map.h"
#include "Manager.h"
#include "ECS/ECS.h"

extern Manager* GameManager;

World::World()
{
    this->init();
};

World::~World() {};

void World::init()
{
    //Game::assets->AddTexture("terrain", "assets/tiles/grass_and_wall.png");
    Game::assets->AddTexture("terrain", "assets/tiles/grass_and_wall_with_borders.png");
    //Game::assets->AddTexture("terrain", "assets/tiles/testing_tiles_draw_and_dont_overlap.png");

    Game::assets->AddTexture("player", "assets/ff_adventure_knight.png");

//    assets->AddTexture("projectile", "assets/projectile_test.png");

    Map* map = new Map("terrain", CONSTANTS_STANDARD_MAP_SCALE, CONSTANTS_STANDARD_TILE_SIZE);
    map->LoadJsonMap("assets/tiles/test_exported_load_map.json", groupColliders, groupMap);

    player = GameManager->addEntity();

    player->addComponent<TransformComponent>(
        CONSTANTS_PLAYER_SPAWN_X * CONSTANTS_STANDARD_TILE_SCALE,
        CONSTANTS_PLAYER_SPAWN_Y * CONSTANTS_STANDARD_TILE_SCALE,
        CONSTANTS_STANDARD_TILE_SIZE,
        CONSTANTS_STANDARD_TILE_SIZE,
        CONSTANTS_STANDARD_TILE_SCALE
    );
    player->addComponent<SpriteComponent>("player", true);
    player->addComponent<KeyboardController>();
    player->addComponent<ColliderComponent>("player");
    player->addGroup(groupPlayers);

    colliders = GameManager->getGroup(groupColliders);
    enemies = GameManager->getGroup(groupEnemies);
    players = GameManager->getGroup(groupPlayers);
    projectiles = GameManager->getGroup(groupProjectiles);
    layers = map->getLayers();

    Game::camera->centerOnEntity(player);

  //    Game::assets->CreateProjectile("projectile", Vector2D(350, 1100), Vector2D(2, 0), 200, 2);
}

void World::update()
{
    SDL_Rect playerCollider = player->getComponent<ColliderComponent>().collider;
    Vector2D playerPos = player->getComponent<TransformComponent>().position;

    GameManager->refresh();
    GameManager->update();

    for (auto& c : colliders)
    {
        SDL_Rect cCollider = c->getComponent<ColliderComponent>().collider;

        if (Collision::AABB(cCollider, playerCollider))
        {
            player->getComponent<TransformComponent>().position = playerPos;
        }
    }

    for(auto& p : projectiles)
    {
        if (Collision::AABB(player->getComponent<ColliderComponent>().collider, p->getComponent<ColliderComponent>().collider))
        {
            // std::cout << "Project HIT PLAYER ~DESTROYED" << std::endl;
            p->destroy();
        }
    }

    Game::camera->update();
};

void World::draw(SDL_Renderer* renderer)
{
   // clear renderer
    SDL_RenderClear(renderer);

    for (Layer* layer : layers)
    {
        for (auto& tile : layer->getTiles())
        {
            tile->draw();
        }
    }

    for (auto& c : colliders)
    {
        c->draw();
    }

    for (auto& e : enemies)
    {
        e->draw();
    }

    for (auto& p : players)
    {
        p->draw();
    }

    for (auto& p : projectiles)
    {
        p->draw();
    }

    // present everything
    SDL_RenderPresent(renderer);
};

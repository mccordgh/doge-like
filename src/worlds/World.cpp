#include "World.h"
#include "utils/Vector2D.h"
#include "ECS/Components.h"
#include "utils/Collision.h"
#include "utils/Map.h"


World::World(Manager* man) : manager(man)
{
    this->init();
};

void World::init()
{
    Game::assets->AddTexture("terrain", "assets/tiles/grass_and_wall.png");
    Game::assets->AddTexture("player", "assets/ff_adventure_knight.png");
//    assets->AddTexture("projectile", "assets/projectile_test.png");

    Map* map = new Map("terrain", CONSTANTS_STANDARD_MAP_SCALE, CONSTANTS_STANDARD_TILE_SIZE);
    map->LoadMap("assets/tiles/simple_1.map", CONSTANTS_MAP_WIDTH_IN_TILES, CONSTANTS_MAP_HEIGHT_IN_TILES, groupColliders, groupMap);

    player = manager->addEntity();

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

    colliders = manager->getGroup(groupColliders);
    enemies = manager->getGroup(groupEnemies);
    players = manager->getGroup(groupPlayers);
    projectiles = manager->getGroup(groupProjectiles);
    tiles = manager->getGroup(groupMap);

  //    Game::assets->CreateProjectile("projectile", Vector2D(350, 1100), Vector2D(2, 0), 200, 2);
}

void World::update()
{
  SDL_Rect playerCollider = player->getComponent<ColliderComponent>().collider;
  Vector2D playerPos = player->getComponent<TransformComponent>().position;

  manager->refresh();
  manager->update();

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

  // keep Game::camera centered on player
  Game::camera.x = player->getComponent<TransformComponent>().position.x - (CONSTANTS_MAP_WIDTH / 2); // half map width
  Game::camera.y = player->getComponent<TransformComponent>().position.y - (CONSTANTS_MAP_HEIGHT / 2); // half map height

  if (Game::camera.x < 0) Game::camera.x = 0;
  if (Game::camera.x > Game::camera.w) Game::camera.x = Game::camera.w;

  if (Game::camera.y < 0) Game::camera.y = 0;
  if (Game::camera.y > Game::camera.h) Game::camera.y = Game::camera.h;
};

void World::draw(SDL_Renderer* renderer){
   // clear renderer
    SDL_RenderClear(renderer);

    for (auto& t : tiles)
    {
        t->draw();
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

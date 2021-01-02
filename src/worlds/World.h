#pragma once

#include <SDL2/SDL.h>
#include "ECS/ECS.h"
#include "utils/Map.h"

class World
{
public:
    World(int playerSpawnX, int playerSpawnY);

    World();
    ~World();

    void update();
    void draw(SDL_Renderer* renderer);

    enum groupLabels : std::size_t
    {
        groupColliders,
        groupEnemies,
        groupMap,
        groupPlayers,
        groupProjectiles,
    };

private:
    Entity* player;

    std::vector<Entity*> colliders;
    std::vector<Entity*> enemies;
    std::vector<Entity*> players;
    std::vector<Entity*> projectiles;
    //std::vector<Entity*> tiles;
    std::vector<Layer*> layers;

    void init(int playerSpawnX, int playerSpawnY);
};

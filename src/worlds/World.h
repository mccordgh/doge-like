#pragma once

#include <SDL2/SDL.h>
#include "ECS/ECS.h"

class World
{
public:
    World(Manager* man);

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
    Manager* manager;
    Entity* player;

    std::vector<Entity*> colliders;
    std::vector<Entity*> enemies;
    std::vector<Entity*> players;
    std::vector<Entity*> projectiles;
    std::vector<Entity*> tiles;

    void init();
};

#pragma once

#include <SDL2/SDL.h>
#include "maps/layers/Layer.h"
#include "EntityManager.h"
#include "Camera.h"
#include "gfx/AssetManager.h"
#include "maps/Map.h"

class World
{
public:
    World() = delete;
    ~World();

    World(SDL_Renderer* rend);

    void init();
    void update();
    void draw();

    EntityManager* getEntityManager();

    static AssetManager* assets;
    static Camera* camera;
    static EntityManager* entityManager;
    static Map* map;

    static int nextPlayerSpawnX;
    static int nextPlayerSpawnY;

private:
    // these are all tracked via layers now
   /* std::vector<Entity*> colliders;
    std::vector<Entity*> enemies;
    std::vector<Entity*> players;
    std::vector<Entity*> projectiles;*/
    //std::vector<Entity*> tiles;
    std::vector<Layer*> layers;

    SDL_Renderer* renderer;
};

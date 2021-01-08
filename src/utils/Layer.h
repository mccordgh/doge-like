#pragma once

#include <string>
#include "ECS/ECS.h"

using namespace std;

class Layer
{
public:
    Layer();
    Layer(string n, int num);

    ~Layer();

    void AddTile(string tileSheetId, int srcX, int srcY, int xpos, int ypos, int tileSize, int mapScale, double parallaxX, double parallaxY);
    void AddEntity(Entity* e);

    string name;
    int number;

    vector<Entity*> getTiles();
    /* vector<Entity*> getColliders();
     vector<Entity*> getEnemies();
     Entity* getPlayer();*/
    vector<Entity*> getEntities();
    //vector<ProjectileComponent*> getProjectiles();

private:
    vector<Entity*> tiles;
    //vector<Entity*> colliders;
    //vector<Entity*> enemies;
    //Entity* player;
    vector<Entity*> entities;
};
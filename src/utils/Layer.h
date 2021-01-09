#pragma once

#include <string>
#include "ECS/ECS.h"

using namespace std;

class Layer
{
public:
    Layer();
    Layer(string n, int num, double scale);

    ~Layer();

    void AddTile(string tileSheetId, int srcX, int srcY, int xpos, int ypos, int tileSize, int mapScale, double parallax);
    void AddEntity(Entity* e, double newScale);

    string name;
    int number;

    double getScale();

    vector<Entity*> getTiles();
    vector<Entity*> getEntities();
    //vector<ProjectileComponent*> getProjectiles();

private:
    double m_scale;

    vector<Entity*> tiles;
    vector<Entity*> entities;
};
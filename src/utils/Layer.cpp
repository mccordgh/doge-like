#include "Layer.h"
#include "Game.h"
#include "ECS/TileComponent.h"

Layer::Layer() {};
Layer::~Layer() {};

Layer::Layer(string n, int num) : name(n), number(num)
{};

void Layer::AddTile(string tileSheetId, int srcX, int srcY, int xpos, int ypos, int tileSize, int mapScale, double parallaxX, double parallaxY)
{
    Entity* tile = World::entityManager->addEntity();

    tile->addComponent<TileComponent>(srcX, srcY, xpos, ypos, tileSize, mapScale, tileSheetId, parallaxX, parallaxY);

    tiles.emplace_back(tile);
}

void Layer::AddEntity(Entity* e)
{
    entities.emplace_back(e);
}

vector<Entity*> Layer::getEntities()
{
    return entities;
}

vector<Entity*> Layer::getTiles()
{
    return tiles;
}
//
//vector<Entity*> Layer::getColliders()
//{
//    return colliders;
//}
//
//vector<Entity*> Layer::getEnemies()
//{
//    return enemies;
//}
//
//Entity* Layer::getPlayer()
//{
//    return player;
//}
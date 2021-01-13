#include "Layer.h"
#include "Game.h"
#include "ECS/TileComponent.h"
#include "ECS/TransformComponent.h"

Layer::Layer()
{
    m_scale = 1;
    number = NULL;
};
Layer::~Layer() {};

Layer::Layer(string n, int num, double scale) : name(n), number(num), m_scale(scale)
{};

void Layer::AddTile(string tileSheetId, int srcX, int srcY, int xpos, int ypos, int tileSize, int mapScale, double parallax)
{
    Entity* tile = World::entityManager->addEntity();

    tile->addComponent<TileComponent>(srcX, srcY, xpos, ypos, tileSize, mapScale * parallax, tileSheetId, parallax);

    tiles.emplace_back(tile);
}

void Layer::AddEntity(Entity* e, double newScale)
{
    e->getComponent<TransformComponent>().scale = newScale;

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

vector<Entity*> Layer::getColliders()
{
    return colliders;
}

double Layer::getScale()
{
    return m_scale;
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
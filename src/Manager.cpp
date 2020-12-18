#include "Manager.h"

Manager::Manager(Game* g): game(g) {};
Manager::~Manager() {};

Game* Manager::getGame() { return game; };

void Manager::update()
{
    for (auto& e : entities) e->update();
}

void Manager::draw()
{
    for (auto& e : entities) e->draw();
}

void Manager::refresh()
{

    for (auto i(0u); i < maxGroups; i += 1)
    {
        auto& v(groupedEntities[i]);
        v.erase(
            std::remove_if(std::begin(v), std::end(v),
                [i](Entity* mEntity)
                {
                    return !mEntity->isActive() || !mEntity->hasGroup(i);
                }),
            std::end(v));
    }

    // remove entities whose "active" is set to false
    entities.erase(std::remove_if(std::begin(entities), std::end(entities),
        [](const std::unique_ptr<Entity>& mEntity)
        {
            return !mEntity->isActive();
        }),
        std::end(entities));
}

void Manager::AddToGroup(Entity* mEntity, Group mGroup)
{
    groupedEntities[mGroup].emplace_back(mEntity);
}

std::vector<Entity*>& Manager::getGroup(Group mGroup)
{
    return groupedEntities[mGroup];
}

Entity* Manager::addEntity()
{
    Entity* e = new Entity();
    std::unique_ptr<Entity> uPtr{ e };

    entities.emplace_back(std::move(uPtr));
    return e;
}

#include "EntityManager.h"
#include "ECS/ECS.h"

EntityManager::EntityManager() {};
EntityManager::~EntityManager() {};

//void EntityManager::update()
//{
//    for (auto& e : entities) e->update();
//}

//void EntityManager::draw()
//{
//    for (auto& e : entities) e->draw();
//}

void EntityManager::refresh()
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

void EntityManager::AddToGroup(Entity* mEntity, Group mGroup)
{
    groupedEntities[mGroup].emplace_back(mEntity);
}

std::vector<Entity*>& EntityManager::getGroup(Group mGroup)
{
    return groupedEntities[mGroup];
}

Entity* EntityManager::addEntity(std::string type = "")
{
    Entity* e = new Entity(type);
    std::unique_ptr<Entity> uPtr{ e };

    entities.emplace_back(std::move(uPtr));

    return e;
}

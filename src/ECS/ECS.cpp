//
//  ECS.cpp
//  2d_game_engine
//
//  Created by Matthew mccord on 8/16/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//


#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

#include "ECS.h"
#include "GameConstants.h"

/* COMPONENT */
// keeps track of ID incrementation
inline ComponentID getNewComponentTypeID()
{
    static ComponentID lastID = 0u;

    return lastID++;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept
{
    static ComponentID typeID = getNewComponentTypeID();

    return typeID;
}

void Component::init() {}
void Component::update() {}
void Component::draw() {}

Component::~Component() {}


/* ENTITY */
Entity::Entity(Manager& mManager) : manager(mManager) {}

void Entity::update()
{
    for (auto& c : components) c->update();
}

void Entity::draw()
{
    for (auto& c : components) c->draw();
}

bool Entity::isActive() const { return active; }
void Entity::destroy() { active = false; }

bool Entity::hasGroup(Group mGroup)
{
    return groupBitset[mGroup];
}

void Entity::addGroup(Group mGroup)
{
    groupBitset[mGroup] = true;
    manager.AddToGroup(this, mGroup);
}

void Entity::delGroup(Group mGroup)
{
    groupBitset[mGroup] = false;
}

template <typename T> bool Entity::hasComponent() const
{
    return componentBitSet[getComponentTypeID<T>()];
}

template <typename T, typename... TArgs>
T& Entity::addComponent(TArgs&&... mArgs)
{
    T* c(new T(std::forward<TArgs>(mArgs)...));
    c->entity = this;

    std::unique_ptr<Component> uPtr{ c };
    components.emplace_back(std::move(uPtr));

    componentArray[getComponentTypeID<T>()] = c;
    componentBitSet[getComponentTypeID<T>()] = true;

    c->init();

    return *c;
}

template <typename T> T& Entity::getComponent() const
{
    auto ptr(componentArray[getComponentTypeID<T>()]);

    return *static_cast<T*>(ptr);
}


/* MANAGER */
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
    Entity* e = new Entity(*this);
    std::unique_ptr<Entity> uPtr{ e };

    entities.emplace_back(std::move(uPtr));
    return e;
}

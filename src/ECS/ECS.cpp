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
#include "Manager.h"

extern Manager* GameManager;

class Manager;

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
Entity::Entity(Manager& mManager) : manager(mManager), active(true) {}

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
    GameManager->AddToGroup(this, mGroup);
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

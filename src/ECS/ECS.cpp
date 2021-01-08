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
#include "Game.h"

class EntityManager;

/* COMPONENT */
// keeps track of ID incrementation
//inline ComponentID getNewComponentTypeID()
//{
//    static ComponentID lastID = 0u;
//
//    return lastID++;
//}

//template <typename T> inline ComponentID getComponentTypeID() noexcept
//{
//    static ComponentID typeID = getNewComponentTypeID();
//
//    return typeID;
//}

void Component::init() {}
void Component::update() {}
void Component::draw() {}

Component::~Component() {}


/* ENTITY */
Entity::Entity() : active(true) {}

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
    Game::stateManager->getState()->getWorld()->getEntityManager()->AddToGroup(this, mGroup);
}

void Entity::delGroup(Group mGroup)
{
    groupBitset[mGroup] = false;
}

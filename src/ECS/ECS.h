//
//  ECS.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/10/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

#include "GameConstants.h"

class Component;
class Entity;
class Manager;

using ComponentID = std::size_t;
using Group = std::size_t; // Groups used for collision layers and render layers

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

constexpr std::size_t maxComponents = CONSTANTS_GROUP_MAX_SIZE;
constexpr std::size_t maxGroups = CONSTANTS_GROUP_MAX_SIZE;

using ComponentBitSet = std::bitset<maxComponents>;
using GroupBitSet = std::bitset<maxGroups>;

using ComponentArray = std::array<Component*, maxComponents>;

class Component
{
public:
    Entity* entity;

    virtual void init() {}
    virtual void update() {}
    virtual void draw() {}

    virtual ~Component() {}
};

class Entity
{
public:
    Entity(Manager& mManager) : manager(mManager) {}

    void update()
    {
        for(auto& c : components) c->update();
    }

    void draw() {
        for(auto& c : components) c->draw();
    }

    bool isActive() const { return active; }
    void destroy() { active = false; }

    bool hasGroup(Group mGroup)
    {
        return groupBitset[mGroup];
    }

    void addGroup(Group mGroup);
    void delGroup(Group mGroup)
    {
        groupBitset[mGroup] = false;
    }

    template <typename T> bool hasComponent() const
    {
        return componentBitSet[getComponentTypeID<T>()];
    }

    template <typename T, typename... TArgs>
    T& addComponent(TArgs&&... mArgs)
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

    template <typename T> T& getComponent() const
    {
        auto ptr(componentArray[getComponentTypeID<T>()]);

        return *static_cast<T*>(ptr);
    }

private:
    Manager& manager;

    bool active = true;
    std::vector<std::unique_ptr<Component>> components;

    ComponentArray componentArray;
    ComponentBitSet componentBitSet;
    GroupBitSet groupBitset;
};

class Manager
{
public:
    Manager() {};
    ~Manager() {};

    void update()
    {
        for (auto& e : entities) e->update();
    }

    void draw()
    {
        for (auto& e : entities) e->draw();
    }

    void refresh()
    {

        for(auto i(0u); i < maxGroups ; i += 1)
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
            [](const std::unique_ptr<Entity> &mEntity)
        {
            return !mEntity->isActive();
        }),
        std::end(entities));
    }

    void AddToGroup(Entity* mEntity, Group mGroup)
    {
        groupedEntities[mGroup].emplace_back(mEntity);
    }

    std::vector<Entity*>& getGroup(Group mGroup)
    {
        return groupedEntities[mGroup];
    }

    Entity* addEntity()
    {
        Entity* e = new Entity(*this);
        std::unique_ptr<Entity> uPtr{ e };

        entities.emplace_back(std::move(uPtr));
        return e;
    }

private:
    std::vector<std::unique_ptr<Entity>> entities;
    std::array<std::vector<Entity*>, maxGroups> groupedEntities;
};

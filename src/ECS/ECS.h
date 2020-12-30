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

class Game;
class Component;
class Entity;
class Manager;

using ComponentID = std::size_t;
using Group = std::size_t; // Groups used for collision layers and render layers

//inline ComponentID getNewComponentTypeID();
// keeps track of ID incrementation
inline ComponentID getNewComponentTypeID()
{
    static ComponentID lastID = 0u;

    return lastID++;
}

//template <typename T> inline ComponentID getComponentTypeID() noexcept;
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

    virtual void init();
    virtual void update();
    virtual void draw();

    virtual ~Component();
};

class Entity
{
public:
    Entity();

    void update();
    void draw();

    bool isActive() const;
    void destroy();

    bool hasGroup(Group mGroup);
    void addGroup(Group mGroup);
    void delGroup(Group mGroup);

   /* template <typename T> bool hasComponent() const;
    template <typename T, typename... TArgs> T& addComponent(TArgs&&... mArgs);
    template <typename T> T& getComponent() const;*/

    template <typename T> bool hasComponent() const
    {
        return componentBitSet[getComponentTypeID<T>()];
    }

    template <typename T, typename... TArgs>
    T& addComponent(TArgs&&... mArgs)
    {
        T* newComponent(new T(std::forward<TArgs>(mArgs)...));
        newComponent->entity = this;

        std::unique_ptr<Component> uPtr{ newComponent };
        components.emplace_back(std::move(uPtr));

        componentArray[getComponentTypeID<T>()] = newComponent;
        componentBitSet[getComponentTypeID<T>()] = true;

        newComponent->init();

        return *newComponent;
    }

    template <typename T> T& getComponent() const
    {
        auto ptr(componentArray[getComponentTypeID<T>()]);

        return *static_cast<T*>(ptr);
    }

private:
    bool active;
    std::vector<std::unique_ptr<Component>> components;

    ComponentArray componentArray;
    ComponentBitSet componentBitSet;
    GroupBitSet groupBitset;
};

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

// keeps track of ID incrementation
inline ComponentID getNewComponentTypeID();

template <typename T> inline ComponentID getComponentTypeID() noexcept;

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

    template <typename T> bool hasComponent() const;
    template <typename T, typename... TArgs> T& addComponent(TArgs&&... mArgs);
    template <typename T> T& getComponent() const;

private:
    bool active;
    std::vector<std::unique_ptr<Component>> components;

    ComponentArray componentArray;
    ComponentBitSet componentBitSet;
    GroupBitSet groupBitset;
};

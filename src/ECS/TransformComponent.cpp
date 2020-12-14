//
//  TransformComponent.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/10/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include "TransformComponent.h"

void TransformComponent::initValues()
{
    height = CONSTANTS_STANDARD_TILE_SIZE;
    width = CONSTANTS_STANDARD_TILE_SIZE;
    scale = CONSTANTS_STANDARD_TILE_SCALE;

    speed = CONSTANTS_STANDARD_MOVE_SPEED;
}

TransformComponent::TransformComponent()
{
    initValues();

    position.x = 0.0f;
    position.y = 0.0f;
}

TransformComponent::TransformComponent(int sc)
{
    initValues();

    // spawn points
    position.x = CONSTANTS_PLAYER_SPAWN_X * CONSTANTS_STANDARD_TILE_SCALE;
    position.y = CONSTANTS_PLAYER_SPAWN_Y * CONSTANTS_STANDARD_TILE_SCALE;
    scale = sc;
}

TransformComponent::TransformComponent(float x, float y)
{
    initValues();

    position.x = x;
    position.y = y;
}

TransformComponent::TransformComponent(float x, float y, int w, int h, int sc)
{
    position.x = x;
    position.y = y;

    height = h;
    width = w;
    scale = sc;

    speed = CONSTANTS_STANDARD_MOVE_SPEED;
}

void TransformComponent::init()
{
    velocity.x = 0.0f;
    velocity.y = 0.0f;
}

void TransformComponent::update()
{
    position.x += velocity.x * speed;
    position.y += velocity.y * speed;
}

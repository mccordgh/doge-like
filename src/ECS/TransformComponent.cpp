//
//  TransformComponent.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/10/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include "TransformComponent.h"


TransformComponent::TransformComponent()
{
    position.x = 0.0f;
    position.y = 0.0f;
}

TransformComponent::TransformComponent(int sc)
{
    // spawn points
    position.x = CONSTANTS_PLAYER_SPAWN_X * CONSTANTS_STANDARD_TILE_SCALE;
    position.y = CONSTANTS_PLAYER_SPAWN_Y * CONSTANTS_STANDARD_TILE_SCALE;
    scale = sc;
}

TransformComponent::TransformComponent(float x, float y)
{
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

//
//  TransformComponent.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/10/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include "Components.h"
#include "../Vector2D.h"
#include "GameConstants.h"

class TransformComponent : public Component
{
public:
    Vector2D position;
    Vector2D velocity;
    
    int height = GameConstants::STANDARD_TILE_SIZE;
    int width = GameConstants::STANDARD_TILE_SIZE;
    int scale = GameConstants::STANDARD_TILE_SCALE;
    
    int speed = GameConstants::STANDARD_MOVE_SPEED;
    
    TransformComponent()
    {
        position.x = 0.0f;
        position.y = 0.0f;
    }
    
    TransformComponent(int sc)
    {
        // Magic numbers are spawn points
        position.x = GameConstants::PLAYER_SPAWN_X * GameConstants::STANDARD_TILE_SCALE;
        position.y = GameConstants::PLAYER_SPAWN_Y * GameConstants::STANDARD_TILE_SCALE;
        scale = sc;
    }
    
    TransformComponent(float x, float y)
    {
        position.x = x;
        position.y = y;
    }
    
    TransformComponent(float x, float y, int w, int h, int sc)
    {
        position.x = x;
        position.y = y;
        
        height = h;
        width = w;
        scale = sc;
    }
    
    void init() override
    {
        velocity.x = 0.0f;
        velocity.y = 0.0f;
    }
    
    void update() override
    {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }
};

//
//  TransformComponent.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/10/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include "Components.h"
#include "Vector2D.h"

class TransformComponent : public Component
{
public:
    Vector2D position;
    Vector2D velocity;
    
    int height = 32;
    int width = 32;
    int scale = 1;
    
    int speed = 3;
    
    TransformComponent()
    {
        position.x = 0.0f;
        position.y = 0.0f;
    }
    
    TransformComponent(int sc)
    {
        position.x = 300;
        position.y = 1200;
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

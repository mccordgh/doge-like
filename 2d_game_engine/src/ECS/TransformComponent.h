//
//  TransformComponent.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/10/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#ifndef TransformComponent_h
#define TransformComponent_h

#include "Components.h"
#include "Vector2D.h"

class TransformComponent : public Component
{
public:
    Vector2D position;
    
    TransformComponent()
    {
        position.x = 0.0f;
        position.y = 0.0f;
    }
    
    TransformComponent(float x, float y)
    {
        position.x = x;
        position.y = y;
    }
    
    void update() override
    {
        
    }
};

#endif /* TransformComponent_h */

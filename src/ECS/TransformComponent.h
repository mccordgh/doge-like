//
//  TransformComponent.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/10/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include "utils/Vector2D.h"
#include "ECS/ECS.h"

class TransformComponent : public Component
{
public:
    Vector2D position;
    Vector2D velocity;

    int height = CONSTANTS_STANDARD_TILE_SIZE;
    int width = CONSTANTS_STANDARD_TILE_SIZE;
    int scale = CONSTANTS_STANDARD_TILE_SCALE;

    int speed = CONSTANTS_STANDARD_MOVE_SPEED;

    TransformComponent();
    TransformComponent(int sc);
    TransformComponent(float x, float y);
    TransformComponent(float x, float y, int w, int h, int sc);

    void init() override;
    void update() override;
};

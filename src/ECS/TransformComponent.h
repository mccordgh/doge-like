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

    int height;
    int width;
    int scale;

    int speed;

    TransformComponent();
    TransformComponent(int sc);
    TransformComponent(float x, float y);
    TransformComponent(float x, float y, int w, int h, int sc);

    void init() override;
    void update() override;

private:
    void initValues();
};

//
//  KeyboardController.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/10/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include "ECS/ECS.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"

class KeyboardController : public Component
{
public:
    TransformComponent *transform;
    SpriteComponent *sprite;

    void init() override;
    void update() override;
};

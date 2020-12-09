//
//  ColliderComponent.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/10/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include <string>
#include "TransformComponent.h"
#include "Game.h"

class ColliderComponent : public Component
{
public:
    SDL_Rect collider;
    std::string tag;

    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;

    TransformComponent* transform;

    ColliderComponent(std::string t);
    ColliderComponent(std::string t, int xpos, int ypos, int size);

    void init() override;
    void update() override;
    void draw() override;

private:
    bool drawTexture = false;
};

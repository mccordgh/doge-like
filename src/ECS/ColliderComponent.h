//
//  ColliderComponent.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/10/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include <string>
#include <SDL2/SDL.h>

#include "Components.h"

class ColliderComponent : public Component
{
public:
    SDL_Rect collider;
    std::string tag;

    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;

    TransformComponent* transform;

    ColliderComponent(std::string t)
    {
        tag = t;
    }

    ColliderComponent(std::string t, int xpos, int ypos, int size)
    {
        tag = t;

        collider.x = xpos;
        collider.y = ypos;
        collider.h = collider.w = size;
    }

    void init() override
    {
        if(!entity->hasComponent<TransformComponent>()) {
            entity->addComponent<TransformComponent>();
        }

        transform = &entity->getComponent<TransformComponent>();

        texture = TextureManager::LoadTexture("assets/tiles/collision_texture.png");
        srcRect = { 0, 0, CONSTANTS_STANDARD_TILE_SIZE, CONSTANTS_STANDARD_TILE_SIZE };
        destRect = { collider.x, collider.y, collider.w, collider.h};
    }

    void update() override
    {
        // we want to run for entities like player, enemy, etc but not static tiles
        if (tag != "terrain")
        {
            collider.x = static_cast<int>(transform->position.x);
            collider.y = static_cast<int>(transform->position.y);
            collider.w = transform->width * transform->scale;
            collider.h = transform->height * transform->scale;
        }

        destRect.x = collider.x - Game::camera.x;
        destRect.y = collider.y - Game::camera.y;
    }

    void draw() override
    {
        if (!drawTexture) return;

        TextureManager::Draw(texture, srcRect, destRect, SDL_FLIP_NONE);
    }

private:
    bool drawTexture = false;
};

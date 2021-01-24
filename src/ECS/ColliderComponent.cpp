//
//  ColliderComponent.cpp
//  2d_game_engine
//
//  Created by Matthew mccord on 8/10/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include <string>

#include "ColliderComponent.h"
#include "TransformComponent.h"
#include "gfx/TextureManager.h"
#include "Game.h"

ColliderComponent::ColliderComponent(std::string t)
{
    tag = t;

    drawTexture = false;
}

ColliderComponent::ColliderComponent(std::string t, int xpos, int ypos, int size)
{
    tag = t;

    collider.x = xpos;
    collider.y = ypos;
    collider.h = collider.w = size;

    drawTexture = false;
}

void ColliderComponent::init()
{
    if (!entity->hasComponent<TransformComponent>()) {
        entity->addComponent<TransformComponent>();
    }

    transform = &entity->getComponent<TransformComponent>();

    if (drawTexture)
    {
        texture = TextureManager::LoadTexture("assets/tiles/collision_texture.png");
    }

    srcRect = { 0, 0, CONSTANTS_STANDARD_TILE_SIZE, CONSTANTS_STANDARD_TILE_SIZE };
    destRect = { collider.x, collider.y, collider.w, collider.h };
}

void ColliderComponent::update()
{
    // we want to run for entities like player, enemy, etc but not static tiles
    if (tag != "terrain")
    {
        collider.x = static_cast<int>(transform->position.x);
        collider.y = static_cast<int>(transform->position.y);
        collider.w = transform->width * transform->scale;
        collider.h = transform->height * transform->scale;
    }

    destRect.x = collider.x - World::camera->xPosition();
    destRect.y = collider.y - World::camera->yPosition();
}

void ColliderComponent::draw()
{
    if (!drawTexture) return;

    TextureManager::Draw(texture, srcRect, destRect, SDL_FLIP_NONE);
}

//
//  ColliderComponent.cpp
//  2d_game_engine
//
//  Created by Matthew mccord on 8/10/20.
//  Copyright � 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include <string>

#include "ColliderComponent.h"
#include "TransformComponent.h"
#include "gfx/TextureManager.h"
#include "Manager.h"

extern Manager* GameManager; 

ColliderComponent::ColliderComponent(std::string t)
{
    tag = t;

    drawTexture = true;
}

ColliderComponent::ColliderComponent(std::string t, int xpos, int ypos, int size)
{
    tag = t;

    collider.x = xpos;
    collider.y = ypos;
    collider.h = collider.w = size;

    drawTexture = true;
}

void ColliderComponent::init()
{
    if (!entity->hasComponent<TransformComponent>()) {
        entity->addComponent<TransformComponent>();
    }

    transform = &entity->getComponent<TransformComponent>();

    texture = TextureManager::LoadTexture("assets/tiles/collision_texture.png");
    srcRect = { 0, 0, CONSTANTS_STANDARD_TILE_SIZE, CONSTANTS_STANDARD_TILE_SIZE };
    destRect = { collider.x, collider.y, collider.w, collider.h };
}

void ColliderComponent::update()
{
    // we want to run for entities like player, enemy, etc but not static tiles
    if (tag != "terrain" && transform != nullptr)
    {
        collider.x = static_cast<int>(transform->position.x);
        collider.y = static_cast<int>(transform->position.y);
        collider.w = transform->width * transform->scale;
        collider.h = transform->height * transform->scale;
    }

    destRect.x = collider.x - GameManager->getGame()->camera.x;
    destRect.y = collider.y - GameManager->getGame()->camera.y;
}

void ColliderComponent::draw()
{
    if (!drawTexture) return;

    TextureManager::Draw(texture, srcRect, destRect, SDL_FLIP_NONE);
}
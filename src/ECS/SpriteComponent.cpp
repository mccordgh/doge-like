//
//  SpriteComponent.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/10/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include "SpriteComponent.h"
#include "Game.h"
#include "gfx/TextureManager.h"


SpriteComponent::SpriteComponent() = default;

SpriteComponent::SpriteComponent(std::string id)
{
    setTexture(id);
}

SpriteComponent::SpriteComponent(std::string id, bool isAnimated)
{
    animated = isAnimated;

    Animation idle = Animation(0, 2, CONSTANTS_STANDARD_ANIMATION_SPEED);
    Animation walk_down = Animation(0, 2, CONSTANTS_STANDARD_ANIMATION_SPEED);
    Animation walk_up = Animation(1, 2, CONSTANTS_STANDARD_ANIMATION_SPEED);
    Animation walk_left = Animation(2, 2, CONSTANTS_STANDARD_ANIMATION_SPEED);

    animations.emplace("idle", idle);
    animations.emplace("walk_down", walk_down);
    animations.emplace("walk_up", walk_up);
    animations.emplace("walk_left", walk_left);

    Play("idle");

    setTexture(id);
}

SpriteComponent::~SpriteComponent() {}

void SpriteComponent::setTexture(std::string id)
{
    texture = Game::assets->GetTexture(id);
}

void SpriteComponent::init()
{
    transform = &entity->getComponent<TransformComponent>();

    srcRect.x = srcRect.y = 0;
    srcRect.w = transform->width;
    srcRect.h = transform->height;
}

void SpriteComponent::update()
{
    if (animated)
    {
        srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
    }

    srcRect.y = animIndex * transform->height;

    destRect.x = static_cast<int>(transform->position.x) - Game::camera.x;
    destRect.y = static_cast<int>(transform->position.y) - Game::camera.y;
    destRect.w = transform->width * transform->scale;
    destRect.h = transform->height * transform->scale;
}

void SpriteComponent::draw()
{
    TextureManager::Draw(texture, srcRect, destRect, spriteFlip);
}

void SpriteComponent::Play(const char* animName)
{
    frames = animations[animName].frames;
    animIndex = animations[animName].index;
    speed = animations[animName].speed;
}

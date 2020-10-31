//
//  SpriteComponent.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/10/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include "Components.h"
#include "TextureManager.h"
#include "Animation.h"
#include <map>

class SpriteComponent : public Component
{
public:
    int animIndex = 0;

    std::map<const char*, Animation> animations;

    SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

    SpriteComponent() = default;
    SpriteComponent(std::string id)
    {
        setTexture(id);
    }

    SpriteComponent(std::string id, bool isAnimated)
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

    ~SpriteComponent() {}

    void setTexture(std::string id)
    {
        texture = Game::assets->GetTexture(id);
    }

    void init() override
    {
        transform = &entity->getComponent<TransformComponent>();

        srcRect.x = srcRect.y = 0;
        srcRect.w = transform->width;
        srcRect.h = transform->height;
    }

    void update() override
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

    void draw() override
    {
        TextureManager::Draw(texture, srcRect, destRect, spriteFlip);
    }

    void Play(const char* animName)
    {
        frames = animations[animName].frames;
        animIndex = animations[animName].index;
        speed = animations[animName].speed;
    }

private:
    TransformComponent *transform;

    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;

    bool animated = false;
    int frames = 0;
    int speed = CONSTANTS_STANDARD_ANIMATION_SPEED;
};

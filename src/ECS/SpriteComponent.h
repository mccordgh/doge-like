//
//  SpriteComponent.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/10/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once


#include <map>
#include "TransformComponent.h"
#include "Animation.h"
#include "Game.h"

class SpriteComponent : public Component
{
public:
    int animIndex = 0;

    std::map<const char*, Animation> animations;

    SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

    SpriteComponent();
    SpriteComponent(std::string id);
    SpriteComponent(std::string id, bool isAnimated);

    ~SpriteComponent();

    void setTexture(std::string id);

    void init() override;
    void update() override;
    void draw() override;

    void Play(const char* animName);

private:
    TransformComponent *transform;

    SDL_Texture *texture;
    SDL_Rect destRect;
    SDL_Rect srcRect;

    bool animated = false;
    int frames = 0;
    int speed = CONSTANTS_STANDARD_ANIMATION_SPEED;
};

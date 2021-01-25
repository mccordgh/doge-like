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
#include "SDL2/SDL.h"

class SpriteComponent : public Component
{
public:
    int animIndex;

    std::map<const char*, Animation> animations;

    SDL_RendererFlip spriteFlip;
    double parallax;

    SpriteComponent();
    SpriteComponent(std::string id, double parallax);
    SpriteComponent(std::string id, double parallax, bool isAnimated);

    ~SpriteComponent();

    void setTexture(std::string id);

    void init() override;
    void update() override;
    void draw() override;

    void Play(const char* animName);

private:
    void setValues(bool isAnimated);

    TransformComponent *transform;

    SDL_Texture *texture;
    SDL_Rect destRect;
    SDL_Rect srcRect;

    bool animated;
    int frames;
    int speed;
};

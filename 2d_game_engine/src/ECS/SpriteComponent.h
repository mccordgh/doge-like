//
//  SpriteComponent.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/10/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include "Components.h"
#include "SDL2/SDL.h"
#include "TextureManager.h"

class SpriteComponent : public Component
{
public:
    SpriteComponent() = default;
    SpriteComponent(const char* name)
    {
        setTexture(name);
    }
    
    SpriteComponent(const char* name, int mFrames, int mSpeed)
    {
        animated = true;
        frames = mFrames;
        speed = mSpeed;
        
        setTexture(name);
    }
    
    ~SpriteComponent()
    {
        SDL_DestroyTexture(texture);
    }
    
    void setTexture(const char* name)
    {
        texture = TextureManager::LoadTexture(name);
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
        
        destRect.x = (int) transform->position.x;
        destRect.y = (int) transform->position.y;
        destRect.w = transform->width * transform->scale;
        destRect.h = transform->height * transform->scale;
    }
    
    void draw() override
    {
        TextureManager::Draw(texture, srcRect, destRect);
    }
    
private:
    TransformComponent *transform;
    
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;
    
    bool animated = false;
    int frames = 0;
    int speed = 100;
};

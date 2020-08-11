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
    
    void setTexture(const char* name)
    {
        texture = TextureManager::LoadTexture(name);
    }
    
    void init() override
    {
        transform = &entity->getComponent<TransformComponent>();
        
        srcRect.x = srcRect.y = 0;
        srcRect.w = srcRect.h = 32;
        
        destRect.w = destRect.h = 64;
    }
    
    void update() override
    {
        destRect.x = (int) transform->position.x;
        destRect.y = (int) transform->position.y;
    }
    
    void draw() override
    {
        TextureManager::Draw(texture, srcRect, destRect);
    }
    
private:
    TransformComponent *transform;
    
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;
};

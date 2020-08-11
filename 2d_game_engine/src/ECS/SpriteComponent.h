//
//  SpriteComponent.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/10/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#ifndef SpriteComponent_h
#define SpriteComponent_h

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
        position = &entity->getComponent<PositionComponent>();
        
        srcRect.x = srcRect.y = 0;
        srcRect.w = srcRect.h = 32;
        
        destRect.w = destRect.h = 64;
    }
    
    void update() override
    {
        destRect.x = position->x();
        destRect.y = position->y();
    }
    
    void draw() override
    {
        TextureManager::Draw(texture, srcRect, destRect);
    }
    
private:
    PositionComponent *position;
    
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;
};

#endif /* SpriteComponent_h */

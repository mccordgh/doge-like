//
//  TileComponent.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/10/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include "ECS.h"
#include "TransformComponent.h"
#include "SDL2/SDL.h"

class TileComponent : public Component
{
public:
    TransformComponent *transform;
    SpriteComponent *sprite;
    
    SDL_Rect tileRect;
    int tileID;
    char* name;
    
    TileComponent() = default;
    
    TileComponent(int x, int y, int w, int h, int id)
    {
        tileRect.x = x;
        tileRect.y = y;
        tileRect.w = w;
        tileRect.h = h;
        
        tileID = id;
        
        switch(tileID)
        {
            case 0:
                name = "water";
                break;
                
            case 1:
                name = "dirt";
                break;
                
            case 2:
                name = "grass";
                break;
        }
    }
    
    void init() override
    {
        entity->addComponent<TransformComponent>((float) tileRect.x, (float) tileRect.y, tileRect.w, tileRect.h, 1);
        transform = &entity->getComponent<TransformComponent>();
        
        entity->addComponent<SpriteComponent>(name);
        sprite = &entity->getComponent<SpriteComponent>();
    }
};

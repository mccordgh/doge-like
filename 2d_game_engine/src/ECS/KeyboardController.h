//
//  KeyboardController.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/10/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include "../Game.hpp"
#include "ECS.h"
#include "Components.h"

class KeyboardController : public Component
{
public:
    TransformComponent *transform;
    SpriteComponent *sprite;
    
    void init() override
    {
        sprite = &entity->getComponent<SpriteComponent>();
        transform = &entity->getComponent<TransformComponent>();
    }
    
    void update() override
    {
        if(Game::event.type == SDL_KEYDOWN)
        {
            switch (Game::event.key.keysym.sym)
            {
                case SDLK_w:
                    transform->velocity.y = -1;
                    break;
                    
                case SDLK_s:
                    transform->velocity.y = 1;
                    break;
                    
                case SDLK_a:
                    transform->velocity.x = -1;
                    sprite->spriteFlip = SDL_FLIP_HORIZONTAL;

                    break;
                    
                case SDLK_d:
                    transform->velocity.x = 1;
                    break;
            }
            
            if (transform->velocity.x != 0 || transform->velocity.y != 0) {
                sprite->Play("walk");
            }
        }
        
        if (Game::event.type == SDL_KEYUP)
        {
            switch (Game::event.key.keysym.sym)
            {
                case SDLK_w:
                    transform->velocity.y = 0;
                    break;
                   
                case SDLK_s:
                    transform->velocity.y = 0;
                    break;
                   
                case SDLK_a:
                    transform->velocity.x = 0;
                    sprite->spriteFlip = SDL_FLIP_NONE;
                    
                    break;
                   
                case SDLK_d:
                    transform->velocity.x = 0;
                    break;
                    
                case SDLK_ESCAPE:
                    Game::isRunning = false;
                    break;
            }
            
            if (transform->velocity.x == 0 && transform->velocity.y == 0) {
                sprite->Play("idle");
            }
            else
            {
                std::cout << transform->position.x << ", " << transform->position.y << std::endl;
            }
        }
    }
};

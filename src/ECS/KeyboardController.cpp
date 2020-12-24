//
//  KeyboardController.cpp
//  2d_game_engine
//
//  Created by Matthew mccord on 8/10/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#include "KeyboardController.h"
#include "Manager.h"

extern Manager* GameManager;

TransformComponent* transform;
SpriteComponent* sprite;

void KeyboardController::init()
{
    sprite = &entity->getComponent<SpriteComponent>();
    transform = &entity->getComponent<TransformComponent>();
}

void KeyboardController::update()
{
    SDL_Event event = Game::event;

    if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_w:
            transform->velocity.y = -1;

            sprite->spriteFlip = SDL_FLIP_NONE;
            sprite->Play("walk_up");
            break;

        case SDLK_s:
            transform->velocity.y = 1;

            sprite->spriteFlip = SDL_FLIP_NONE;
            sprite->Play("walk_down");
            break;

        case SDLK_a:
            transform->velocity.x = -1;

            sprite->spriteFlip = SDL_FLIP_NONE;
            sprite->Play("walk_left");
            break;

        case SDLK_d:
            transform->velocity.x = 1;

            sprite->Play("walk_left");
            sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
            break;
        }
    }

    if (event.type == SDL_KEYUP)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_w:
            transform->velocity.y = 0;
            break;

        case SDLK_s:
            transform->velocity.y = 0;
            break;

        case SDLK_a:
            transform->velocity.x = 0;
            break;

        case SDLK_d:
            transform->velocity.x = 0;
            break;

        case SDLK_ESCAPE:
            Game::isRunning = false;
            break;
        }

        if (transform->velocity.x == 0 && transform->velocity.y == 0) {
            sprite->spriteFlip = SDL_FLIP_NONE;
            sprite->Play("idle");
        }
    }
}

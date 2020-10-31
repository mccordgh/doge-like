//
//  TileComponent.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/10/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include "ECS.h"

class TileComponent : public Component
{
public:
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;

    Vector2D position;

    TileComponent() = default;

    ~TileComponent()
    {
        SDL_DestroyTexture(texture);
    }

    TileComponent(int srcX, int srcY, int xpos, int ypos, int tileSize, int tileScale, std::string id)
    {
        texture = Game::assets->GetTexture(id);

        position.x = xpos;
        position.y = ypos;

        srcRect.x = srcX;
        srcRect.y = srcY;
        srcRect.w = srcRect.h = tileSize;

        destRect.x = xpos;
        destRect.y = ypos;
        destRect.w = destRect.h = tileSize * tileScale;
    }

    void update() override
    {
        destRect.x = position.x - Game::camera.x;
        destRect.y = position.y - Game::camera.y;
    }

    void draw() override
    {
        TextureManager::Draw(texture, srcRect, destRect, SDL_FLIP_NONE);
    }
};

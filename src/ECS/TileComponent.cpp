//
//  TileComponent.cpp
//  2d_game_engine
//
//  Created by Matthew mccord on 8/10/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include "TileComponent.h"
#include "gfx/TextureManager.h"
#include "Game.h"
#include "SDL2/SDL.h"

TileComponent::TileComponent() = default;

TileComponent::~TileComponent()
{
    SDL_DestroyTexture(texture);
}

TileComponent::TileComponent(int srcX, int srcY, int xpos, int ypos, int tileSize, int tileScale, std::string id, double para)
{
    texture = World::assets->GetTexture(id);

    position.x = xpos;
    position.y = ypos;

    srcRect.x = srcX;
    srcRect.y = srcY;
    srcRect.w = srcRect.h = tileSize;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = destRect.h = tileSize * tileScale;

    parallax = para;
}

void TileComponent::update()
{
    destRect.x = position.x - (World::camera->xPosition() * parallax);
    destRect.y = position.y - (World::camera->yPosition() * parallax);
}

void TileComponent::draw()
{
    TextureManager::Draw(texture, srcRect, destRect, SDL_FLIP_NONE);
}

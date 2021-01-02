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
#include "Manager.h"
#include "SDL2/SDL.h"

extern Manager* GameManager;

TileComponent::TileComponent() = default;

TileComponent::~TileComponent()
{
    SDL_DestroyTexture(texture);
}

TileComponent::TileComponent(int srcX, int srcY, int xpos, int ypos, int tileSize, int tileScale, std::string id, double paraX, double paraY)
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

    parallaxX = paraX;
    parallaxY = paraY;
}

void TileComponent::update()
{
    destRect.x = position.x - (Game::camera->xPosition() * parallaxX);
    destRect.y = position.y - (Game::camera->yPosition() * parallaxY);
}

void TileComponent::draw()
{
    TextureManager::Draw(texture, srcRect, destRect, SDL_FLIP_NONE);
}

//
//  GameObject.cpp
//  2d_game_engine
//
//  Created by Matthew mccord on 8/9/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#include "GameObject.h"
#include "TextureManager.h"
#include "GameConstants.h"

GameObject::GameObject(const char* textureSheet, int x, int y)
{
    objTexture = TextureManager::LoadTexture(textureSheet);
    
    xpos = x;
    ypos = y;
}

GameObject::~GameObject() {}

void GameObject::Update()
{
    srcRect.h = GameConstants::STANDARD_TILE_SIZE;
    srcRect.w = GameConstants::STANDARD_TILE_SIZE;
    srcRect.x = 0;
    srcRect.y = 0;
    
    destRect.h = srcRect.h * GameConstants::STANDARD_TILE_SCALE;
    destRect.w = srcRect.w * GameConstants::STANDARD_TILE_SCALE;
    destRect.x = xpos;
    destRect.y = ypos;
}

void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

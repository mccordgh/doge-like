//
//  TextureManager.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/9/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include "Game.h"

class TextureManager
{
public:
    static SDL_Texture* LoadTexture(const char* fullpath);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip);
};

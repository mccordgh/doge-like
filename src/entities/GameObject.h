//
//  GameObject.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/9/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include "SDL2/SDL.h"

class GameObject
{
public:
    GameObject(const char* textureSheet, int x, int y);
    ~GameObject();
    
    void Update();
    void Render();
    
private:
    SDL_Texture* objTexture;
    
    SDL_Rect srcRect;
    SDL_Rect destRect;
    
    int xpos;
    int ypos;
};

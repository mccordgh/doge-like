//
//  Game.hpp
//  2d_game_engine
//
//  Created by Matthew mccord on 7/21/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include "SDL2/SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>

class ColliderComponent;

class Game
{
public:
    Game();
    ~Game();
    
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    
    void handleEvents();
    void update();
    void render();
    void clean();
    
    bool running() { return isRunning; }
    
    static void AddTile(int srcX, int srcY, int xpos, int ypos);
    
    static SDL_Renderer *renderer;
    static SDL_Event event;
    static std::vector<ColliderComponent*> colliders;
    static bool isRunning;

    // camera object maybe move to its own class
    static SDL_Rect camera;
    
private:
    int count = 0;
    
    SDL_Window *window;
};

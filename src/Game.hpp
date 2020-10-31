//
//  Game.hpp
//  2d_game_engine
//
//  Created by Matthew mccord on 7/21/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include "StateManager.h"
#include "AssetManager.h"

class Game
{
public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void draw();
    void clean();

    bool running() { return isRunning; }

    static SDL_Renderer *renderer;
    static SDL_Event event;
    static bool isRunning;

    // camera object maybe move to its own class
    static SDL_Rect camera;
    static AssetManager* assets;
    static StateManager* stateManager;

private:
    SDL_Window *window;
};

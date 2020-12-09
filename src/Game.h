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
#include "states/StateManager.h"
#include "gfx/AssetManager.h"

class Game
{
public:
    static void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    static void handleEvents();
    static void update();
    static void draw();
    static void clean();

    static SDL_Renderer *renderer;
    static SDL_Event event;
    static bool isRunning;

    // camera object maybe move to its own class
    static SDL_Rect camera;
    static AssetManager* assets;
    static StateManager* stateManager;

private:
    static SDL_Window *window;
};

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
#include "Camera.h"

class Game
{
public:
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void draw();
    void clean();

    bool running();

    static SDL_Renderer *renderer;
    static SDL_Event event;
    static bool isRunning;

    static Camera* camera;
    static AssetManager* assets;

private:
    StateManager* stateManager;

    SDL_Window *window;
};

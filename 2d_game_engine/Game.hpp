//
//  Game.hpp
//  2d_game_engine
//
//  Created by Matthew mccord on 7/21/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include "SDL2/SDL.h"
#include <iostream>

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

private:
    bool isRunning;
    int count = 0;
    
    SDL_Window *window;
    SDL_Renderer *renderer;
};

#endif /* Game_hpp */

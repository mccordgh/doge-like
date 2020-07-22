//
//  Game.cpp
//  2d_game_engine
//
//  Created by Matthew mccord on 7/21/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#include "Game.hpp"

Game::Game() {}
Game::~Game() {}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    // Check that SDL initialized correctly
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL2 Subsystems Initialized" << std::endl;
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        
        if (window)
        {
            std::cout << "Window created!" << std::endl;
        }
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            
            std::cout << "Renderer created!" << std::endl;
        }
        
        isRunning = true;
    } else {
        // SDL Did not initialize correctly if we hit this else
        isRunning = false;
    }
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    
    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
            
        default:
            break;
    }
}

void Game::update()
{
    count++;
    
    if (count > 120)
    {
        count = 0;
    }
    
    std::cout << "counter: " << count << std::endl;
    
}

void Game::render()
{
    SDL_RenderClear(renderer);
    // draw things here
    
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    
    SDL_Quit();
    
    std::cout << "Game Cleaned" << std::endl;
    std::cin.get();
}

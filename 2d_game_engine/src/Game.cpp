//
//  Game.cpp
//  2d_game_engine
//
//  Created by Matthew mccord on 7/21/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#include "Game.hpp"

SDL_Texture* playerTexture;
SDL_Rect sourceRect, destinationRect;

enum Direction { NW, NE, SE, SW };

int xx = 0, yy = 0;
Direction dir = SE;

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
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
            
            std::cout << "Renderer created!" << std::endl;
        }
        
        isRunning = true;
    } else {
        // SDL Did not initialize correctly if we hit this else
        isRunning = false;
    }
    
    SDL_Surface* tmpSurface = IMG_Load("assets/player.png");
    std::cout << "IMG_Load Error: " << IMG_GetError() << std::endl << std::endl;
    playerTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    
    destinationRect.h = 64;
    destinationRect.w = 64;
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
    switch (dir) {
        case NW:
            xx -= 2;
            yy -= 2;
            
            if (xx < 0) {
                xx = 0;
                dir = NE;
                break;
            }
            
            if (yy < 0) {
                yy = 0;
                dir = SW;
            }
            break;
            
        case NE:
            xx += 2;
            yy -= 2;
            
            if (xx > 800 - 64) {
                xx = 800 - 64;
                dir = NW;
                break;
            }
            
            if (yy < 0) {
                yy = 0;
                dir = SE;
            }
            break;
            
        case SE:
            xx += 2;
            yy += 2;
            
            if (xx > 800-64) {
                xx = 800-64;
                dir = SW;
                break;
            }
            
            if (yy > 600-64) {
                yy = 600-64;
                dir = NE;
            }
            break;
            
        case SW:
            xx -= 2;
            yy += 2;
            
            if (xx < 0) {
                xx = 0;
                dir = SE;
                break;
            }
            
            if (yy > 600-64) {
                yy = 600-64;
                dir = NW;
            }
            break;
            
        default:
            break;
    }
    
    destinationRect.x = xx;
    destinationRect.y = yy;
}

void Game::render()
{
    // Always first?
    SDL_RenderClear(renderer);
    
    SDL_RenderCopy(renderer, playerTexture, NULL, &destinationRect);
    
    // Always last?
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

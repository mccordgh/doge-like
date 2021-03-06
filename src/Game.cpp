//
//  Game.cpp
//  2d_game_engine
//
//  Created by Matthew mccord on 7/21/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#include "Game.h"
#include "worlds/World.h"
#include "states/State.h"

bool Game::isRunning = false;

SDL_Event Game::event;
StateManager* Game::stateManager = new StateManager();
SDL_Renderer* Game::renderer = nullptr;

bool Game::running() { return isRunning; }

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
        renderer = SDL_CreateRenderer(window, -1, 0);

        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        }

        if (!window || !renderer) throw;

        isRunning = true;
    } else {
        // SDL Did not initialize correctly if we hit this else
        isRunning = false;

        return;
    }

    World* world = new World(renderer);
    State* state = new State(world);

    world->init();
    stateManager->setState(state);
}

void Game::handleEvents()
{
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
    stateManager->update();
}

void Game::draw()
{
    stateManager->draw();
}

void Game::clean()
{
    delete stateManager;

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    SDL_Quit();

    std::cout << "Game Cleaned" << std::endl;
    std::cin.get();
}

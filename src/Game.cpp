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

Manager* manager = new Manager();

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    Game::isRunning = false;
    int flags = 0;

    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    // Check that SDL initialized correctly
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL2 Subsystems Initialized" << std::endl;

        Game::window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        Game::renderer = SDL_CreateRenderer(window, -1, 0);

        if (Game::renderer)
        {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        }

        if (!Game::window || !Game::renderer) throw;

        Game::isRunning = true;
    } else {
        // SDL Did not initialize correctly if we hit this else
        Game::isRunning = false;

        return;
    }

    Game::camera = {0, 0, CONSTANTS_MAP_WIDTH, CONSTANTS_MAP_HEIGHT};

    World* world = new World(manager);
    State* state = new State(world);

    Game::stateManager = new StateManager(state);
    Game::stateManager->setState(state);
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
    Game::stateManager->update();
}

void Game::draw()
{
    Game::stateManager->draw(renderer);
}

void Game::clean()
{
    delete Game::stateManager;

    SDL_DestroyWindow(Game::window);
    SDL_DestroyRenderer(Game::renderer);

    SDL_Quit();

    std::cout << "Game Cleaned" << std::endl;
    std::cin.get();
}

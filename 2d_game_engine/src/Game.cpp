//
//  Game.cpp
//  2d_game_engine
//
//  Created by Matthew mccord on 7/21/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#include "ECS/Components.h"
#include "Game.hpp"
#include "TextureManager.h"
#include "Map.h"
#include "Vector2D.h"
#include "Collision.h"

Map* map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

std::vector<ColliderComponent*> Game::colliders;

auto& wall(manager.addEntity());
auto& tile0(manager.addEntity());
auto& tile1(manager.addEntity());
auto& tile2(manager.addEntity());

auto& player(manager.addEntity());

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
    
    map = new Map();
    
    tile0.addComponent<TileComponent>(200, 200, 32, 32, 0);
    tile0.addComponent<ColliderComponent>("water");
    tile1.addComponent<TileComponent>(300, 300, 32, 32, 1);
    tile1.addComponent<ColliderComponent>("dirt");
    tile2.addComponent<TileComponent>(400, 400, 32, 32, 2);
    tile2.addComponent<ColliderComponent>("grass");

    player.addComponent<TransformComponent>(2);
    player.addComponent<SpriteComponent>("player");
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");
    
    wall.addComponent<TransformComponent>(500.0f, 300.0f, 20, 300, 1);
    wall.addComponent<SpriteComponent>("dirt");
    wall.addComponent<ColliderComponent>("wall");
}

void Game::handleEvents() {
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
    manager.refresh();
    manager.update();
    
    for (auto cc : colliders)
    {
        Collision::AABB(player.getComponent<ColliderComponent>(), *cc);
    }
 }

void Game::render()
{
    SDL_RenderClear(renderer);
    
//    map->DrawMap();
    manager.draw();
    
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    delete map;
    
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    
    SDL_Quit();
    
    std::cout << "Game Cleaned" << std::endl;
    std::cin.get();
}

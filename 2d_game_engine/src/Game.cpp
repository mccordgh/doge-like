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

Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

// camera object x, y, width of map, height of map
SDL_Rect Game::camera = {0, 0, 800, 640};

Map* map;

auto& player(manager.addEntity());

bool Game::isRunning = false;

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
    
    map = new Map("tiles/terrain_sheet", 3, 32);
    map->LoadMap("assets/tiles/map1.txt", 25, 20);

    player.addComponent<TransformComponent>(2);
    player.addComponent<SpriteComponent>("player_anims", true);
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");
    player.addGroup(groupPlayers);
}

auto& tiles(manager.getGroup(Game::groupMap));
auto& players(manager.getGroup(Game::groupPlayers));
auto& enemies(manager.getGroup(Game::groupEnemies));
auto& colliders(manager.getGroup(Game::groupColliders));

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
    SDL_Rect playerCollider = player.getComponent<ColliderComponent>().collider;
    Vector2D playerPos = player.getComponent<TransformComponent>().position;
    
    manager.refresh();
    manager.update();
    
    for (auto& c : colliders)
    {
        SDL_Rect cCollider = c->getComponent<ColliderComponent>().collider;
        
        if (Collision::AABB(cCollider, playerCollider))
        {
            player.getComponent<TransformComponent>().position = playerPos;
        }
    }
    
    camera.x = player.getComponent<TransformComponent>().position.x - 400; // 400 is half map width
    camera.y = player.getComponent<TransformComponent>().position.y - 320; // 320 is half map height
    
    if (camera.x < 0) camera.x = 0;
    if (camera.x > camera.w) camera.x = camera.w;

    if (camera.y < 0) camera.y = 0;
    if (camera.y > camera.h) camera.y = camera.h;
}

void Game::render()
{
    // clear renderer
    SDL_RenderClear(renderer);
    
    for (auto& t : tiles)
    {
        t->draw();
    }
    
    for (auto& c : colliders)
    {
        c->draw();
    }
    
    for (auto& e : enemies)
    {
        e->draw();
    }
    
    for (auto& p : players)
    {
        p->draw();
    }
    
    // present everything
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

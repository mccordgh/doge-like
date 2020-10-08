//
//  Game.cpp
//  2d_game_engine
//
//  Created by Matthew mccord on 7/21/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#include "Components.h"
#include "Game.hpp"
#include "TextureManager.h"
#include "Map.h"
#include "Vector2D.h"
#include "Collision.h"
#include "GameConstants.h"

Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

// camera object x, y, width of map, height of map (width & height hardcoded to 25, 20 for now)
const int mapWidthInTiles = 25;
const int mapHeightInTiles = 20;
const int mapWidth = mapWidthInTiles * (GameConstants::STANDARD_TILE_SIZE * GameConstants::STANDARD_TILE_SCALE);
const int mapHeight = mapHeightInTiles * (GameConstants::STANDARD_TILE_SIZE * GameConstants::STANDARD_TILE_SCALE);
SDL_Rect Game::camera = {0, 0, mapWidth, mapHeight};

AssetManager* Game::assets = new AssetManager(&manager);
Map* map;

auto& player(manager.addEntity());

bool Game::isRunning = false;

Game::Game() {}
Game::~Game() {}

// IF CAMERA BOUNDS SEEM OFF ITS MOST LIKELY DUE TO A SCALING ISSUE

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
    
    assets->AddTexture("terrain", "assets/tiles/grass_and_wall.png");
    assets->AddTexture("player", "assets/ff_adventure_knight.png");
//    assets->AddTexture("projectile", "assets/projectile_test.png");
    
    // Magic number for scale because somethign weird is going on with Map
    map = new Map("terrain", GameConstants::STANDARD_MAP_SCALE, GameConstants::STANDARD_TILE_SIZE);
    map->LoadMap("assets/tiles/simple_1.map", mapWidthInTiles, mapHeightInTiles);

    // magic numbers are just spawn points right now
    player.addComponent<TransformComponent>(
        GameConstants::PLAYER_SPAWN_X * GameConstants::STANDARD_TILE_SCALE,
        GameConstants::PLAYER_SPAWN_Y * GameConstants::STANDARD_TILE_SCALE,
        GameConstants::STANDARD_TILE_SIZE,
        GameConstants::STANDARD_TILE_SIZE,
        GameConstants::STANDARD_TILE_SCALE
    );
    player.addComponent<SpriteComponent>("player", true);
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");
    player.addGroup(groupPlayers);
    
//    assets->CreateProjectile("projectile", Vector2D(350, 1100), Vector2D(2, 0), 200, 2);
}

auto& colliders(manager.getGroup(Game::groupColliders));
auto& enemies(manager.getGroup(Game::groupEnemies));
auto& players(manager.getGroup(Game::groupPlayers));
auto& projectiles(manager.getGroup(Game::groupProjectiles));
auto& tiles(manager.getGroup(Game::groupMap));

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
    
    for(auto& p : projectiles)
    {
        if (Collision::AABB(player.getComponent<ColliderComponent>().collider, p->getComponent<ColliderComponent>().collider))
        {
            // std::cout << "Project HIT PLAYER ~DESTROYED" << std::endl;
            p->destroy();
        }
    }
    
    // keep camera centered on player
    camera.x = player.getComponent<TransformComponent>().position.x - (mapWidth / 2); // half map width
    camera.y = player.getComponent<TransformComponent>().position.y - (mapHeight / 2); // half map height
    
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
    
    for (auto& p : projectiles)
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

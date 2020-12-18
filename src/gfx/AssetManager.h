//
//  AssetManager.h
//  2d_game_engine
//
//  Created by Matthew mccord on 9/14/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include <unordered_map>
#include <SDL2/SDL.h>
#include <iostream>
//#include "ECS/ECS.h"

class AssetManager
{
public:
    AssetManager();
    ~AssetManager();
    
    //game objects
    //void CreateProjectile(std::string id, Vector2D pos, Vector2D velocity, int range, int speed);

    //texture management
    void AddTexture(std::string id, const char* path);

    SDL_Texture* GetTexture(std::string id);

private:
    std::unordered_map<std::string, SDL_Texture*> textures;
};

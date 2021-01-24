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

using namespace std;

class AssetManager
{
public:
    AssetManager();
    ~AssetManager();

    //game objects
    //void CreateProjectile(string id, Vector2D pos, Vector2D velocity, int range, int speed);

    //texture management
    void AddTexture(string id, string path);

    SDL_Texture* GetTexture(string id);

private:
    unordered_map<string, SDL_Texture*> textures;
};

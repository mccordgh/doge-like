//
//  AssetManager.h
//  2d_game_engine
//
//  Created by Matthew mccord on 9/14/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include <map>
#include <string>
#include "TextureManager.h"
#include "Vector2D.h"
#include "ECS/ECS.h"

class AssetManager
{
public:
    AssetManager(Manager* man);
    ~AssetManager();
    
    //game objects
    void CreateProjectile(std::string id, Vector2D pos, Vector2D velocity, int range, int speed);
    
    //texture management
    void AddTexture(std::string id, const char* path);
    
    SDL_Texture* GetTexture(std::string id);
    
private:
    Manager* manager;
    
    std::map<std::string, SDL_Texture*> textures;
};

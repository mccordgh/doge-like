//
//  AssetManager.cpp
//  2d_game_engine
//
//  Created by Matthew mccord on 9/14/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#include "AssetManager.h"
#include "TextureManager.h"

AssetManager::AssetManager(Manager* man): manager(man)
{}

AssetManager::~AssetManager()
{}

// void AssetManager::CreateProjectile(std::string id, Vector2D pos, Vector2D velocity, int range, int speed)
// {
//     auto& projectile(manager->addEntity());

//     projectile.addComponent<TransformComponent>(pos.x, pos.y, CONSTANTS_STANDARD_TILE_SIZE, CONSTANTS_STANDARD_TILE_SIZE, CONSTANTS_STANDARD_TILE_SCALE);
//     projectile.addComponent<SpriteComponent>(id, false);
//     projectile.addComponent<ProjectileComponent>(velocity, range, speed);
//     projectile.addComponent<ColliderComponent>("projectile");
//     projectile.addGroup(groupProjectiles);
// }

void AssetManager::AddTexture(std::string id, const char *path)
{
    textures.emplace(id, TextureManager::LoadTexture(path));
}

SDL_Texture* AssetManager::GetTexture(std::string id)
{
    return textures[id];
}


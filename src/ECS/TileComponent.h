//
//  TileComponent.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/10/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include "ECS/ECS.h"
#include "utils/Vector2D.h"
#include "SDL2/SDL.h"

class TileComponent : public Component
{
public:
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;

    Vector2D position;

    TileComponent();
    TileComponent(int srcX, int srcY, int xpos, int ypos, int tileSize, int tileScale, std::string id);

    ~TileComponent();

    void update() override;
    void draw() override;
};

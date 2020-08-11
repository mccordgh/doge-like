//
//  Collision.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/10/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include "SDL2/SDL.h"

class Collision
{
public:
    // Axis Aligned Bounding Box collision (2 rectangles)
    static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
};

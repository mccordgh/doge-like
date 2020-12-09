//
//  Animation.cpp
//  2d_game_engine
//
//  Created by Matthew mccord on 8/18/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include "Animation.h"

Animation::Animation() {};

Animation::Animation(int i, int f, int s)
{
    index = i;
    frames = f;
    speed = s;
}

//
//  Animation.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/18/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

struct Animation
{
    int index;
    int frames;
    int speed;
    
    Animation() {}
    Animation(int i, int f, int s)
    {
        index = i;
        frames = f;
        speed = s;
    }
};

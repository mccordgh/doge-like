//
//  Map.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/9/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once
#include <string>

class Map
{
public:
    Map();
    ~Map();
    
    static void LoadMap(std::string path, int sizeX, int sizeY);
};

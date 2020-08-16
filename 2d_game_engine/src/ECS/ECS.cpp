//
//  ECS.cpp
//  2d_game_engine
//
//  Created by Matthew mccord on 8/16/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#include "ECS.h"

void Entity::addGroup(Group mGroup)
{
    groupBitset[mGroup] = true;
    manager.AddToGroup(this, mGroup);
}

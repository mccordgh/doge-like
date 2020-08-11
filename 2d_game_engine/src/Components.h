//
//  Components.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/10/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#ifndef Components_h
#define Components_h

#include "ECS.h"

class PositionComponent : public Component
{
public:
    int x() { return xpos; }
    int y() { return ypos; }
    
    void init() override
    {
        xpos = 0;
        ypos = 0;
    }
    
    void update() override
    {
        xpos++;
        ypos++;
    }
    
    void setPos(int x, int y)
    {
        xpos = x;
        ypos = y;
    }
    
private:
    int xpos;
    int ypos;
};

#endif /* Components_h */

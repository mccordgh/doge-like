//
//  PositionComponent.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/10/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#ifndef PositionComponent_h
#define PositionComponent_h

#include "Components.h"

class PositionComponent : public Component
{
public:
    PositionComponent()
    {
        xpos = 0;
        ypos = 0;
    }
    
    PositionComponent(int x, int y)
    {
        xpos = x;
        ypos = y;
    }

    int x() { return xpos; }
    int y() { return ypos; }
    
    void x(int x) { xpos = x; }
    void y(int y) { ypos = y; }
    
    void setPos(int x, int y)
    {
        xpos = x;
        ypos = y;
    }
    
    void update() override
    {
        xpos++;
        ypos++;
    }
    
private:
    int xpos;
    int ypos;
};

#endif /* PositionComponent_h */

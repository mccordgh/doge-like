#pragma once

#include "worlds/World.h"

class State
{
  public:
    State(World* w);

    World* getWorld();

    void update();
    void draw();

  private:
    World* world;
};

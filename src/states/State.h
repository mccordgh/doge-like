#pragma once

#include "worlds/World.h"

class State
{
  public:
    State(World* w);

    void update();
    void draw(SDL_Renderer* renderer);

  private:
    World* world;
};

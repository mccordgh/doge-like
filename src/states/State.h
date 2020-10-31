#pragma once

#include "World.h"

class State
{
  public:
    State(World* w): world(w) {};

    void update() {
      world->update();
    };

    void draw(SDL_Renderer* renderer)
    {
      world->draw(renderer);
    };

  private:
    World* world;
};

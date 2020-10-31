#pragma once

#include "State.h"
#include "World.h"

class GameState : public State
{
  public:
    GameState::GameState(World* wld) {};
    ~GameState() {};

    void update() {};
    void draw() {};

  private:
    World* world;
};

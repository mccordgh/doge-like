#pragma once

#include "State.h"

class StateManager
{
  public:
    StateManager(State* state);

    void update()
    {
      currentState->update();
    };

    void draw(SDL_Renderer* renderer)
    {
      currentState->draw(renderer);
    };

    State getState()
    {
      return *currentState;
    };

    void setState(State* state)
    {
      currentState = state;
    };

  private:
    State* currentState;
};
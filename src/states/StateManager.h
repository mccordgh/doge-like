#pragma once

#include "State.h"

class StateManager
{
public:
    StateManager(State* state);

    void update();
    void draw(SDL_Renderer* renderer);
    State* getState();
    void setState(State* state);

private:
    State* currentState;
};
#pragma once

#include "State.h"

class StateManager
{
public:
    StateManager();

    void update();
    void draw();
    State* getState();
    void setState(State* state);

private:
    State* currentState;
};
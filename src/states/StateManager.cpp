#pragma once

#include "StateManager.h"

StateManager::StateManager()
{
    currentState = nullptr;
};

void StateManager::update()
{
    if (currentState != nullptr)
    {
        currentState->update();
    }
};

void StateManager::draw()
{
    if (currentState != nullptr)
    {
        currentState->draw();
    }
};

State* StateManager::getState()
{
    return currentState;
};

void StateManager::setState(State* state)
{
    currentState = state;
};

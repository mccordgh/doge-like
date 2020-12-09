#pragma once

#include "StateManager.h"

StateManager::StateManager(State* state) : currentState(state) {};

void StateManager::update()
{
    currentState->update();
};

void StateManager::draw(SDL_Renderer* renderer)
{
    currentState->draw(renderer);
};

State* StateManager::getState()
{
    return currentState;
};

void StateManager::setState(State* state)
{
    currentState = state;
};

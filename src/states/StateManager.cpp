#include "StateManager.h"

StateManager::StateManager(State* state): currentState(state)
{
  currentState = state;
};

StateManager::~StateManager() {};

void StateManager::update()
{
  currentState->update();
};

void StateManager::draw(){
  currentState->draw();
};

State StateManager::getState()
{
  return *currentState;
};

void StateManager::setState(State* state)
{
  currentState = state;
};
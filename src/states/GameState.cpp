#include "GameState.h"
#include "World.h"

GameState::GameState(World* wld): world(wld)
{};

GameState::~GameState() {};

void GameState::update()
{
  world->update();
};

void GameState::draw(){
  world->draw();
};

#pragma once

#include "State.h"


State::State(World* w) : world(w) {};

void State::update()
{
    world->update();
};

void State::draw(SDL_Renderer* renderer)
{
    world->draw(renderer);
};


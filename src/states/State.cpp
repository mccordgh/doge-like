#pragma once

#include "State.h"


State::State(World* w) : world(w) {};

void State::update()
{
    world->update();
};

void State::draw()
{
    world->draw();
};

World* State::getWorld()
{
    return world;
}


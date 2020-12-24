#pragma once

#include "Game.h"

class Manager
{
public:
    Manager();
    ~Manager();

    void update();
    void draw();
    void refresh();

    void AddToGroup(Entity* mEntity, Group mGroup);

    std::vector<Entity*>& getGroup(Group mGroup);

    Entity* addEntity();

private:
    std::vector<std::unique_ptr<Entity>> entities;
    std::array<std::vector<Entity*>, maxGroups> groupedEntities;
};

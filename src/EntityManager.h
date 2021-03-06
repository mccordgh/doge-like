#pragma once

#include <vector>
#include <array>
#include <string>
#include "ECS/ECS.h"

using namespace std;

class EntityManager
{
public:
    EntityManager();
    ~EntityManager();

    //void update();
    //void draw();
    void refresh();

    //void setMapSize(int width, int height);
    //int mapHeight();
    //int mapWidth();

    enum groupLabels : std::size_t
    {
        groupColliders,
        groupEnemies,
        groupMap,
        groupPlayers,
        groupProjectiles,
        groupTiles,
        groupTriggers,
    };

    void AddToGroup(Entity* mEntity, Group mGroup);

    std::vector<Entity*>& getGroup(Group mGroup);

    Entity* addEntity(string name);

private:
    std::vector<std::unique_ptr<Entity>> entities;
    std::array<std::vector<Entity*>, maxGroups> groupedEntities;

    //int currentMapHeight;
    //int currentMapWidth;
};

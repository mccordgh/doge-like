#include "ObjectLayer.h"
#include "ECS/TransformComponent.h"
#include "worlds/World.h"
#include "ECS/Components.h"

void ObjectLayer::AddEntity(string type, int xpos, int ypos, int width, int height, int scale)
{
    // We dont need to create an entity just save the spawn point for the player on this map.
    if (type == "PlayerSpawn")
    {
        World::nextPlayerSpawnX = xpos * scale;
        World::nextPlayerSpawnY = ypos * scale;

        return;
    }

    Entity* entity = World::entityManager->addEntity();

    entity->addComponent<TransformComponent>(xpos, ypos, width, height, scale);
    entity->addComponent<SpriteComponent>(type, true);
    entity->addComponent<ColliderComponent>(type);

    if (type == "Player")
    {
        entity->addComponent<KeyboardController>();
        entity->addGroup(World::entityManager->groupPlayers);
    }
    else if (type == "Trigger")
    {
        entity->addGroup(World::entityManager->groupTriggers);
    }
    else
    {
        throw std::runtime_error(string("Unknown entity Type in ObjectLayer::AddEntity: " + type));
    }

    entities.emplace_back(entity);
}

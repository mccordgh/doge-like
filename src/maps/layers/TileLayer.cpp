#include "TileLayer.h"
#include "ECS/ECS.h"
#include "worlds/World.h"
#include "ECS/TileComponent.h"

void TileLayer::AddTile(string tileSheetId, int srcX, int srcY, int xpos, int ypos, int tileSize, int mapScale, double parallax)
{
    Entity* tile = World::entityManager->addEntity();

    tile->addComponent<TileComponent>(srcX, srcY, xpos, ypos, tileSize, mapScale * parallax, tileSheetId, parallax);
    tile->addGroup(World::entityManager->groupTiles);

    tiles.emplace_back(tile);
}

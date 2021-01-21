#pragma once

#include <vector>

#include "Layer.h"
#include "ECS/ECS.h"

using namespace std;

class TileLayer : public Layer
{
public:
	vector<Entity*> tiles;
	int height;
	int width;

	void AddTile(string tileSheetId, int srcX, int srcY, int xpos, int ypos, int tileSize, int mapScale, double parallax);
};
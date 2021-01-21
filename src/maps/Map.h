#pragma once

#include <vector>
#include <string>

#include "layers/LayerGroup.h"
#include "TileSet.h"

using namespace std;

class Map
{
public:
	int height;
	vector<LayerGroup*> layerGroups;
	int nextLayerId;
	int nextObjectId;
	int tileHeight;
	vector<TileSet*> tileSets;
	int tileWidth;
	string type;
	int width;
};
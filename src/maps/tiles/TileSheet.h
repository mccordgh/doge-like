#pragma once

#include <string>
#include "TileWithObjects.h"

using namespace std;

class TileSheet
{
public:
	int columns;
	string imageName;
	int imageHeight;
	int imageWidth;
	int margin;
	string name;
	int spacing;
	int tileCount;
	int tileHeight;
	vector<TileWithObjects> tiles;
	int tilesWidth;
	string type;
	string version;
	string textureId;
};
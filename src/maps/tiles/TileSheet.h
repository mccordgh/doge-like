#pragma once

#include <string>
#include "Tile.h"

using namespace std;

class TileSheet
{
public:
	int columns;
	string image;
	int imageHeight;
	int imageWidth;
	int margin;
	string name;
	int spacing;
	int tileCount;
	int tileHeight;
	vector<Tile*> tiles;
	int tilesWidth;
	string type;
	string version;
};
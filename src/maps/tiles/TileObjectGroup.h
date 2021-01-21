#pragma once

#include <string>
#include <vector>
#include "TileObject.h"

using namespace std;

class TileObjectGroup
{
public:
	string drawOrder;
	int id;
	string name;
	vector<TileObject> objects; // <= this array of data in the json with key "objects" will be converted to entities during map load
	double opacity;
	string type;
	bool visible;
	int x;
	int y;
};

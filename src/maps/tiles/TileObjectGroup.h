#pragma once

#include <string>
#include <vector>
#include "ECS/ECS.h"

using namespace std;

class TileObjectGroup
{
public:
	string drawOrder;
	int id;
	string name;
	vector<Entity*> objects; // <= this array of data in the json with key "objects" will be converted to entities during map load
	double opacity;
	string type;
	bool visible;
	int x;
	int y;
};

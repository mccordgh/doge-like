#pragma once

#include <string>

using namespace std;

class TileObject
{
public:
	int height;
	int width;
	int id;
	string type;
	int x;
	int y;
	bool visible;
};

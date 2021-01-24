#pragma once

#include <string>
#include "tiles/TileSheet.h"

using namespace std;

class TileSet
{
public:
	int firstId;
	int lastId;
	TileSheet tileSheet;
};
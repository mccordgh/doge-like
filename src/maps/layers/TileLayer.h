#pragma once

#include <vector>

#include "Layer.h"

using namespace std;

class TileLayer : public Layer
{
public:
	vector<int> tiles;
	int height;
	int width;
};
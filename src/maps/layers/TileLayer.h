#pragma once

#include <vector>

#include "Layer.h"

using namespace std;

class TileLayer : public Layer
{
public:
	vector<int> tiles();
	int height();
	int width();

private:
	vector<int> m_tiles; // <= comes from "data" json key. array of tile ids for each tile in the layer.
	int m_height;
	int m_width;
};
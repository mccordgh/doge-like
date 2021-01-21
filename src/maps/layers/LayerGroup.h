#pragma once

#include <vector>
#include <string>

#include "Layer.h"
#include "TileLayer.h"
#include "ObjectLayer.h"

using namespace std;

class LayerGroup
{
public:
	int id;
	vector<TileLayer> tileLayers;
	vector<ObjectLayer> objectLayers;
	string name;
	double opacity;
	string type;
	bool visible;
	int x;
	int y;
};
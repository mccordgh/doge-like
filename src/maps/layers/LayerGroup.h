#pragma once

#include <vector>
#include <string>

#include "Layer.h"

using namespace std;

class LayerGroup
{
public:
	int id;
	vector<Layer*> layers;
	string name;
	double opacity;
	string type;
	bool visible;
	int x;
	int y;
};
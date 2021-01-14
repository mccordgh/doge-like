#pragma once

#include "Layer.h"
#include <vector>

class LayerGroup
{
public:
	vector<Layer*> layers();

private:
	vector<Layer*> m_layers;
};
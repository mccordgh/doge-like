#pragma once

#include <vector>
#include <string>

#include "Layer.h"

using namespace std;

class LayerGroup
{
public:
	int id();
	vector<Layer*> layers();
	string name();
	double opacity();
	string type();
	bool visible();
	int x();
	int y();

private:
	int m_id;
	vector<Layer*> m_layers;
	string m_name;
	double m_opacity;
	string m_type;
	bool m_visible;
	int m_x;
	int m_y;
};
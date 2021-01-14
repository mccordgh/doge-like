#pragma once

#include <string>
#include <vector>
#include "ECS/ECS.h"

using namespace std;

class TileObjectGroup
{
public:
	string drawOrder();
	int id();
	string name();
	vector<Entity*> objects(); // <= this array of data in the json with key "objects" will be converted to entities during map load
	double opacity();
	string type();
	bool visible();
	int x();
	int y();

private:
	string m_drawOrder;
	int m_id;
	string m_name;
	vector<Entity*> m_objects;
	double m_opacity;
	string m_type;
	bool m_visible;
	int m_x;
	int m_y;
};

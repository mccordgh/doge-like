#pragma once

#include <string>
#include <vector>
#include "TileObject.h"

using namespace std;

class TileObjectGroup
{
public:
	string drawOrder();
	int id();
	string name();
	vector<TileObject*> objects();
	int opacity();
	string type();
	bool visible();
	int x();
	int y();

private:
	string m_drawOrder;
	int m_id;
	string m_name;
	vector<TileObject*> m_objects;
	int m_opacity;
	string m_type;
	bool m_visible;
	int m_x;
	int m_y;
};

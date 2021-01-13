#pragma once

#include <string>

using namespace std;

class TileObject
{
public:
	int height();
	int id();
	string name();
	int rotation();
	string type();
	bool visible();
	int width();
	int x();
	int y();

private:
	int m_height;
	int m_id;
	string m_name;
	int m_rotation;
	string m_type;
	bool m_visible;
	int m_width;
	int m_x;
	int m_y;
};

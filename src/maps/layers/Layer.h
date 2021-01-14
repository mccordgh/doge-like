#pragma once

#include <string>

using namespace std;

class Layer
{
public:
	int id();
	string name();
	double opacity();
	string type();
	bool visible();
	int x();
	int y();

protected:
	int m_id;
	string m_name;
	double m_opacity;
	string m_type;
	bool m_visible;
	int m_x;
	int m_y;
};
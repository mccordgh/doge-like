#pragma once

#include <string>

using namespace std;

class Layer
{
public:
	int id;
	string name;
	double opacity;
	string type;
	bool visible;
	int x;
	int y;
	int parallaxX;
	int parallaxY;
};
#pragma once

#include "Layer.h"
#include "ECS/ECS.h"

class ObjectLayer: public Layer
{
public:
	string drawOrder;
	vector<Entity*> entities; // <= this array of data in the json with key "objects" will be converted to entities during map load

	void AddEntity(string type, int xpos, int ypos, int width, int height, int scale, double parallax);
};
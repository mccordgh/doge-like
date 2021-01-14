#pragma once

#include "Layer.h"
#include "ECS/ECS.h"

class ObjectLayer: public Layer
{
public:
	string drawOrder();
	vector<Entity*> objects(); // <= this array of data in the json with key "objects" will be converted to entities during map load

private:
	string m_drawOrder;
	vector<Entity*> m_objects;
};
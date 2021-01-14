#include "ObjectLayer.h"

string ObjectLayer::drawOrder()
{
	return m_drawOrder;
}

vector<Entity*> ObjectLayer::objects()
{
	return m_objects;
}

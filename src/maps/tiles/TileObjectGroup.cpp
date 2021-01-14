#include "TileObjectGroup.h"

string TileObjectGroup::drawOrder()
{
	return m_drawOrder;
}

int TileObjectGroup::id()
{
	return m_id;
}

string TileObjectGroup::name()
{
	return m_name;
}

vector<Entity*> TileObjectGroup::objects()
{
	return m_objects;
}

double TileObjectGroup::opacity()
{
	return m_opacity;
}

string TileObjectGroup::type()
{
	return m_type;
}

bool TileObjectGroup::visible()
{
	return m_visible;
}

int TileObjectGroup::x()
{
	return m_x;
}

int TileObjectGroup::y()
{
	return m_y;
}

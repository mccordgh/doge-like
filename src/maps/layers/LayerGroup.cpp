#include "LayerGroup.h"

int LayerGroup::id()
{
	return m_id;
}

vector<Layer*> LayerGroup::layers()
{
	return m_layers;
}

string LayerGroup::name()
{
	return m_name;
}

double LayerGroup::opacity()
{
	return m_opacity;
}

string LayerGroup::type()
{
	return m_type;
}

bool LayerGroup::visible()
{
	return m_visible;
}

int LayerGroup::x()
{
	return m_x;
}

int LayerGroup::y()
{
	return m_y;
}

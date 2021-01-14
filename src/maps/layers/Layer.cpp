#include "Layer.h"

int Layer::id()
{
	return m_id;
}

string Layer::name()
{
	return m_name;
}

double Layer::opacity()
{
	return m_opacity;
}

string Layer::type()
{
	return m_type;
}

bool Layer::visible()
{
	return m_visible;
}

int Layer::x()
{
	return m_x;
}

int Layer::y()
{
	return m_y;
}

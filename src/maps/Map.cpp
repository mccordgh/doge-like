#include "Map.h"

int Map::height()
{
	return m_height;
}
bool Map::infinite()
{
	return m_infinite;
}

vector<LayerGroup*> Map::layerGroups()
{
	return m_layerGroups;
}

int Map::nextLayerId()
{
	return m_nextLayerId;
}

int Map::nextObjectId()
{
	return m_nextObjectId;
}

string Map::orientation()
{
	return m_orientation;
}

string Map::renderOrder()
{
	return m_renderOrder;
}

string Map::tiledVersion()
{
	return m_tiledVersion;
}

int Map::tileHeight()
{
	return m_tileHeight;
}

vector<TileSet*> Map::tileSets()
{
	return m_tileSets;
}

int Map::tileWidth()
{
	return m_tileWidth;
}

string Map::type()
{
	return m_type;
}

double Map::version()
{
	return m_version;
}

int Map::width()
{
	return m_width;
}

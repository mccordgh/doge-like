#pragma once

#include "TileObjectGroup.h"

class Tile
{
public:
	int id();
	TileObjectGroup& objectGroup();

private:
	int m_id;
	TileObjectGroup& m_objectGroup;
};

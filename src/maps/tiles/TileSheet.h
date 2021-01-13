#pragma once

#include <string>
#include "Tile.h"

using namespace std;

class TileSheet
{
public:
	int columns();
	string image();
	int imageHeight();
	int imageWidth();
	int margin();
	string name();
	int spacing();
	int tileCount();
	int tileHeight();
	vector<Tile*> tiles();
	int tilesWidth();
	string type();
	string version();

private:
	int m_columns;
	string m_image;
	int m_imageHeight;
	int m_imageWidth;
	int m_margin;
	string m_name;
	int m_spacing;
	int m_tileCount;
	int m_tileHeight;
	vector<Tile*> m_tiles;
	int m_tilesWidth;
	string m_type;
	string m_version;
};
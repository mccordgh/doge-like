#include "TileSheet.h"

int TileSheet::columns()
{
	return m_columns;
}
string TileSheet::image()
{
	return m_image;
}
int TileSheet::imageHeight()
{
	return m_imageHeight;
}
int TileSheet::imageWidth()
{
	return m_imageWidth;
}
int TileSheet::margin()
{
	return m_margin;
}
string TileSheet::name()
{
	return m_name;
}
int TileSheet::spacing()
{
	return m_spacing;
}
int TileSheet::tileCount()
{
	return m_tileCount;
}
int TileSheet::tileHeight()
{
	return m_tileHeight;
		}
vector<Tile*> TileSheet::tiles()
{
	return m_tiles;
}
int TileSheet::tilesWidth()
{
	return m_tilesWidth;
}
string TileSheet::type()
{
	return m_type;
}
string TileSheet::version()
{
	return m_version;
}

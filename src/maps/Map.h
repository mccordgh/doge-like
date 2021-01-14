#pragma once

#include <vector>
#include <string>

#include "layers/LayerGroup.h"
#include "TileSet.h"

using namespace std;

class Map
{
public:
	int height();
	bool infinite();
	vector<LayerGroup*> layerGroups();
	int nextLayerId();
	int nextObjectId();
	string orientation();
	string renderOrder();
	string tiledVersion();
	int tileHeight();
	vector<TileSet*> tileSets();
	int tileWidth();
	string type();
	double version();
	int width();

private:
	int m_height;
	bool m_infinite;
	vector<LayerGroup*> m_layerGroups;
	int m_nextLayerId;
	int m_nextObjectId;
	string m_orientation;
	string m_renderOrder;
	string m_tiledVersion;
	int m_tileHeight;
	vector<TileSet*> m_tileSets;
	int m_tileWidth;
	string m_type;
	double m_version;
	int m_width;
};
#pragma once

#include <string>

using namespace std;

class TileSet
{
public:
	int firstGid();
	string source();

private:
	int m_firstGid;
	string m_source;
};
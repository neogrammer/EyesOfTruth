#include "Tilemap.h"
#include <fstream>
#include <core/globals.h>
using namespace std;

Tilemap::Tilemap(sf::Vector2i mapSize_, const std::string& tilesetFile_, Cfg::Textures tilesetID_, const std::string& tilemapFile_)
	: mapWidth{mapSize_.x}
	, mapHeight{mapSize_.y}
{
	tset.textureID = tilesetID_;

	ifstream in{ tilesetFile_ };

	if (!in.is_open())
	{
		return;
	}
	else
	{

		int tilesizeX, tilesizeY;
		in >> tilesizeX >> tilesizeY;
		tileWidth = tilesizeX;
		tileHeight = tilesizeY;
		int pitch, numTiles;
		in >> pitch >> numTiles;
		int rows = (int)std::ceil((float)numTiles / (float)pitch);
		for (int y = 0; y < rows; y++)
			for (int x  =0; x < pitch;  x++)
			{
				int tileNum = y * pitch + x;
				if (tileNum >= numTiles)
					break;
				int solid;
				in >> solid;
				bool bSolid = (solid == 1) ? true : false;
				Tile t{ bSolid, {x,y}, {(float)tilesizeX, (float)tilesizeY}, {0.f,0.f}, tset, {0.f,0.f} };
				t.addMap(*this);
				tset.addTile(t);
			}
	
		in.close();
	}

	ifstream inMap{ tilemapFile_ };

	if (!inMap.is_open())
	{
		return;
	}
	else
	{
		for (int y = 0; y < mapHeight; y++)
			for (int x = 0; x < mapWidth; x++)
			{
				int idx;
				inMap >> idx;
				this->addTile(idx, { (float)x * (float)tileWidth, (float)y * (float)tileHeight });
				if (this->tiles.back().solid)
				{
					solidTiles.push_back(&tiles[tiles.size() - 1]);
				}
			}

		inMap.close();
	}
}

const Tile& Tilemap::getTile(int index)
{
	return tiles.at(index);
}

const Tile& Tilemap::getTile(int col, int row)
{
	int index = row * mapWidth + col;
	return getTile(index);
}

void Tilemap::addTile(int tileNum, sf::Vector2f pos_)
{
	tiles.push_back(tset.copyTile(tileNum));
	tiles[tiles.size() - 1].setPos(pos_);
	if (tileWidth == 0)
		tileWidth = (int)tiles.back().getSize().x;
	if (tileHeight == 0)
		tileHeight = (int)tiles.back().getSize().y;
}

void Tilemap::renderSolids()
{
	for (auto& t : tiles)
	{
		gWnd.draw(*t.sprite());
	}
}

#pragma once
#include "../core/Cfg.h"
#include "Tileset.h"
#include <string>
class Tilemap
{
	Tileset tset{};

	std::vector<Tile> tiles{};
	std::vector<Tile*> solidTiles{};
	int mapWidth, mapHeight;
	int tileWidth{ 0 }, tileHeight{ 0 };
public:
	explicit Tilemap(sf::Vector2i mapSize_, const std::string& tilesetFile_, Cfg::Textures tilesetID_, const std::string& tilemapFile_);


	const Tile& getTile(int index);
	const Tile& getTile(int col, int row);

	void addTile(int tileNum, sf::Vector2f pos_);

	void renderSolids();
};
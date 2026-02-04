#pragma once
#include "../Obj.h"
class Tileset;
class Tilemap;
class Tile : public Obj
{
	float hh{ 0 }, hw{ 0 };
public:
	using Obj::Obj;
	Tile();
	Tile(bool solid_, sf::Vector2i locationTilesheet_, sf::Vector2f size_, sf::Vector2f positionMap_, Tileset& tileset_, sf::Vector2f offset_);
	void addMap(Tilemap& map_);
	~Tile() override;
	Tile(const Tile& o);
	Tile& operator=(const Tile& o);
	int column{ 0 }, row{ 0 };
	bool solid{ true };
	
	Tileset* tileset{ nullptr };
	Tilemap* tilemap{ nullptr };

};
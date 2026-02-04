#pragma once
#include <vector>
#include <core/Cfg.h>

#include "../Obj.h"
#include <SFML/Graphics/Rect.hpp>
#include "Tile.h"
class Tileset
{
public:
	Cfg::Textures textureID{ Cfg::Textures::Default };
	std::vector<Tile> tiles{};

	void addTile(Tile& t);

	Tile copyTile(int index);
};
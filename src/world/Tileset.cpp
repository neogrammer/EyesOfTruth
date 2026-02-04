#include "Tileset.h"
#include <iostream>
void Tileset::addTile(Tile& t)
{
	if (this->textureID == Cfg::Textures::Default)
		textureID = t.getTexID();


	tiles.push_back(static_cast<Tile&&>(t));

}

Tile Tileset::copyTile(int index)
{
	if (index < 0 || index >= tiles.size())
	{
		std::cout << "trying to copy a tile index not in the container!" << std::endl;
		return static_cast<Tile&&>(Tile{});
	}

	return tiles.at(index);
}
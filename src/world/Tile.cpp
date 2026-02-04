#include "Tile.h"
#include "Tileset.h"
#include "Tilemap.h"

Tile::Tile()
{
}

Tile::Tile(bool solid_, sf::Vector2i locationTilesheet_, sf::Vector2f size_, sf::Vector2f positionMap_, Tileset& tileset_, sf::Vector2f offset_)
	: Obj(tileset_.textureID, sf::IntRect{ {(int)locationTilesheet_.x * (int)size_.x, (int)locationTilesheet_.y * (int)size_.y},{(int)size_.x,(int) size_.y} }, true, positionMap_, size_, offset_)
	, tileset{ &tileset_ }
	, tilemap{nullptr}
	, solid{solid_}
{
	column = locationTilesheet_.x;
	row = locationTilesheet_.y;
	hh = size_.y / 2;
	hw = size_.x / 2;

	setSize(size_);


}

void Tile::addMap(Tilemap& map_)
{
	tilemap = &map_;
}

Tile::~Tile()
{
}

Tile::Tile(const Tile& o)
	: Obj{*dynamic_cast<Obj*>(const_cast<Tile*>(&o))}
	, tileset{o.tileset}
	, tilemap{ o.tilemap }
	, solid{o.solid}
{
	Tile& me = *this;
	me.column = o.column;
	me.row = o.row;
	me.hh = o.size.y / 2;
	me.hw = o.size.x / 2;

	me.setSize(o.size);
}

Tile& Tile::operator=(const Tile& o)
{
	Tile& me = *this;
	me.tilemap = o.tilemap;
	me.texID = o.texID;
	me.texRect = o.texRect;
	me.uniDirectional = o.uniDirectional;
	me.position = o.position;
	me.size = o.size;
	me.offset = o.offset;
	me.facingRight = o.facingRight;

	me.tileset = o.tileset;
	me.solid = o.solid;
	me.column = o.column;
	me.row = o.row;
	me.hh = me.size.y / 2;
	me.hw = me.size.x / 2;

	return me;
}

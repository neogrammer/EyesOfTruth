#pragma once
#include "ObjBase.h"

enum class TextureID
{
	Default,
	Count
};

#include <SFML/Graphics.hpp>
class Obj : public ObjBase
{
	sf::Vector2f position;
	sf::Vector2f offset;
	TextureID texID;
	sf::IntRect texRect;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;

	bool uniDirectional;

protected:

	sf::Vector2f size;
	bool facingRight;

	void setRect(sf::IntRect rect_);
	void setID(TextureID texID_);
	void setOffset(sf::Vector2f offset_);
	void setAccleration(sf::Vector2f offset_);
	void setPos(sf::Vector2f pos_);
	void move(sf::Vector2f amt_);
	bool isFacingRight();
	bool isUniDirectional();


public:
	Obj(TextureID texID_, sf::IntRect texRect_, bool uniDirectional_ = false, sf::Vector2f position_ = {0.f,0.f}, sf::Vector2f size_ = {0.f,0.f}, sf::Vector2f offset_ = {0.f,0.f});
	~Obj();
	sf::Vector2f getOffset();
	sf::Vector2f getAcceleration();

	

	sf::Vector2f getPos();

	std::unique_ptr<sf::Sprite> sprite();
	virtual void update(float dt_, sf::RenderWindow& wnd_);

};

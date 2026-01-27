#pragma once
#include "ObjBase.h"

enum class TextureID
{
	
	Default,
	Count,
	None,
	
};

#include <SFML/Graphics.hpp>
class Obj : public ObjBase
{
	sf::Vector2f position;
	
	TextureID texID;
	sf::IntRect texRect;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::Vector2f offset;
	sf::Vector2f size;
	bool facingRight{ true };
	bool uniDirectional;
	static sf::Texture defaultTex;
public:

	void setUniDirectional(bool cond_);
	void setFacingRight(bool cond_);
	void setSize(sf::Vector2f);
	void setOffset(sf::Vector2f);
	void setRect(sf::IntRect rect_);
	void setID(TextureID texID_);
	void setAccleration(sf::Vector2f offset_);
	void setPos(sf::Vector2f pos_);
	void setVel(sf::Vector2f vel_);
	sf::Vector2f getVel();
	void move(sf::Vector2f amt_);

public:
	Obj();
	Obj(TextureID texID_, sf::IntRect texRect_, bool uniDirectional_ = false, sf::Vector2f position_ = {0.f,0.f}, sf::Vector2f size_ = {0.f,0.f}, sf::Vector2f offset_ = {0.f,0.f});
	~Obj();

	sf::Vector2f getOffset();
	sf::Vector2f getAcceleration();
	bool isFacingRight();
	bool isUniDirectional();
	sf::Vector2f getPos();
	sf::Vector2f getSize();
	sf::Vector2f getVelocity();
	TextureID getTexID();

	std::unique_ptr<sf::Sprite> sprite();
	virtual void update(float dt_, sf::RenderWindow& wnd_);
};

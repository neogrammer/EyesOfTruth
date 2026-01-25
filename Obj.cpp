#include "Obj.h"

void Obj::setRect(sf::IntRect rect_)
{
    texRect = rect_;
}

void Obj::setID(TextureID texID_)
{
    texID = texID_;
}

void Obj::setOffset(sf::Vector2f offset_)
{
    offset = offset_;
}

void Obj::setAccleration(sf::Vector2f acceleration_)
{
    acceleration = acceleration_;
}

Obj::Obj(TextureID texID_, sf::IntRect texRect_, bool uniDirectional_, sf::Vector2f position_, sf::Vector2f size_, sf::Vector2f offset_)
    : texID{texID_}
    , texRect{texRect_}
    , uniDirectional{uniDirectional_}
    , position{position_}
    , size{size_}
    , offset{offset_}
    , facingRight{true}
{
}

Obj::~Obj()
{
}

sf::Vector2f Obj::getOffset()
{
    return offset;
}

sf::Vector2f Obj::getAcceleration()
{
    return acceleration;
}

sf::Vector2f Obj::getPos()
{
    return position;
}

void Obj::setPos(sf::Vector2f pos_)
{
    position = pos_;
}

void Obj::move(sf::Vector2f amt_)
{
    position += amt_;
}

bool Obj::isFacingRight()
{
    if (uniDirectional) return false;

    if (facingRight)
        return true;
    else
        return false;
}

bool Obj::isUniDirectional()
{
    return uniDirectional;
}

std::unique_ptr<sf::Sprite> Obj::sprite()
{
    sf::Texture tex{ "aTex.png" };
    std::unique_ptr<sf::Sprite> out = std::make_unique<sf::Sprite>(tex);  //  Get from Cfg::Textures
    out->setPosition(position - offset);
    return std::move(out);
}

void Obj::update(float dt_, sf::RenderWindow& wnd_)
{
    // friction
    if (velocity.x > 0.f) velocity.x -= 0.009f;
    if (velocity.x < 0.f) velocity.x += 0.009f;

    velocity += acceleration;
    position += velocity * dt_;
    acceleration = { 0.f,0.f };
}

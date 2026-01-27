#include "Obj.h"

sf::Texture Obj::defaultTex = sf::Texture{ "Assets/textures/invariant.png" };


void Obj::setRect(sf::IntRect rect_)
{
    texRect = rect_;
}

void Obj::setID(TextureID texID_)
{
    texID = texID_;
}

void Obj::setUniDirectional(bool cond_)
{
    uniDirectional = cond_;
}

void Obj::setFacingRight(bool cond_)
{
    facingRight = cond_;
}

void Obj::setSize(sf::Vector2f size_)
{
    size = size_;
}

void Obj::setOffset(sf::Vector2f offset_)
{
    offset = offset_;
}

void Obj::setAccleration(sf::Vector2f acceleration_)
{
    acceleration = acceleration_;
}

Obj::Obj()
    : texID{ TextureID::None}
    , texRect{ sf::IntRect{{0,0},{32,32}} }
    , uniDirectional{ false }
    , position{ 0.f,0.f }
    , size{ 32.f, 32.f }
    , offset{ 0.f,0.f }
    , facingRight{ true }
{
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

TextureID Obj::getTexID()
{
    return texID;
}

sf::Vector2f Obj::getPos()
{
    return position;
}

sf::Vector2f Obj::getSize()
{
    return size;
}

sf::Vector2f Obj::getVelocity()
{
    return velocity;
}

void Obj::setPos(sf::Vector2f pos_)
{
    position = pos_;
}

void Obj::setVel(sf::Vector2f vel_)
{
    velocity = vel_;
}

sf::Vector2f Obj::getVel()
{
    return velocity;
}

void Obj::move(sf::Vector2f amt_)
{
    position += amt_;
}

bool Obj::isFacingRight()
{
    if (uniDirectional) return true;

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

    std::unique_ptr<sf::Sprite> out;

    if (texID == TextureID::Default)
    {
       out = std::make_unique<sf::Sprite>(defaultTex);  //  Get from Cfg::Textures
    }
    else
    {
        //out = std::make_unique<sf::Sprite>(Cfg::textures.get((int)texID);  //  Get from Cfg::Textures
    }
    
    out->setPosition(position - offset);
    out->setTextureRect(texRect);

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

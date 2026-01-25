#include "AnimObj.h"
#include <iostream>
void AnimObj::setBase()
{
	if (!anims.contains(currentAnim))
	{
		std::cout << "Current Animation is not in the set for this entity" << std::endl;
	}

	if (!anims.contains(currentIndex))
	{
		std::cout << "Current Index out of range in current animation" << std::endl;
	}

	int currDir = (Obj::facingRight) ? 1 : 0;
	Obj::offset = offsets[currentAnim][currDir][currentIndex];
	Obj::size = sizes[currentAnim][currDir][currentIndex];
}

AnimObj::AnimObj(TextureID texID_, sf::IntRect texRect_, bool uniDirectional_, sf::Vector2f position_, sf::Vector2f size_, sf::Vector2f offset_)
	: Obj{texID_, texRect_,uniDirectional_, position_, size_, offset_}
{
	
}

AnimObj::~AnimObj()
{
}

sf::IntRect AnimObj::getCurrentFrame()
{
	int currDir = (Obj::facingRight) ? 1 : 0;
	return frames[currentAnim][currDir][currentIndex];
}

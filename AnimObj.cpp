#include "AnimObj.h"
#include <iostream>
void AnimObj::setBase()
{
	if (!anims.contains(currentAnim))
	{
		std::cout << "Current Animation is not in the set for this entity" << std::endl;
		return;
	}


	int currDir = (Obj::facingRight) ? 1 : 0;
	if (currentIndex < 0 || currentIndex >= frames[currentAnim].at(currDir).size())
	{
		std::cout << "Current Index out of range in current animation" << std::endl;
		return;
	}

      offset = offsets[currentAnim][currDir][currentIndex];
      size = sizes[currentAnim][currDir][currentIndex];
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
	return { {0,0},{1,1} }; // frames[currentAnim][currDir][currentIndex];
}

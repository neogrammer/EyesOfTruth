#include "AnimObj.h"
#include <iostream>


void AnimObj::setBase()
{
	if (!anims.contains(currentAnim))
	{
		std::cout << "Current Animation is not in the set for this entity" << std::endl;
		return;
	}


	int currDir = (this->isFacingRight()) ? 1 : 0;
	if (currentIndex < 0 || currentIndex >= frames[currentAnim].at(currDir).size())
	{
		std::cout << "Current Index out of range in current animation" << std::endl;
		return;
	}

	setOffset(offsets[currentAnim][currDir][currentIndex]);
      setSize( sizes[currentAnim][currDir][currentIndex] );
}

void AnimObj::loadAnimation(AnimName nameID_, TextureID texID_, std::vector<sf::IntRect>& rects_, std::vector<sf::Vector2f>& offsets_, std::vector<sf::Vector2f>& sizes_, std::vector<float>& delays_, bool loadFirstValue, bool loopWaits_, bool loopDelay_, bool looping_, bool playing_)
{
	if (anims.contains(nameID_))
	{
		std::cout << "Animation already exists! Bouncing back." << std::endl;
		return;
	}

	anims.emplace(nameID_);
	frames[nameID_] = std::vector<std::vector<sf::IntRect>>{};
	offsets[nameID_] = std::vector<std::vector<sf::Vector2f>>{};
	sizes[nameID_] = std::vector<std::vector<sf::Vector2f>>{};
	delays[nameID_] = std::vector<std::vector<float>>{};




	frames[nameID_].push_back(std::vector<sf::IntRect>{});
	frames[nameID_][0].clear();
	if (this->isUniDirectional())
	{
		frames[nameID_][0].reserve(rects_.size());
		for (int i = 0; i < rects_.size(); i++)
			frames[nameID_][0].emplace_back(rects_[i]);
	}
	else
	{
		frames[nameID_][0].reserve(rects_.size() / 2);
		for (size_t i = 0; i < rects_.size() / 2; i++)
			frames[nameID_][0].emplace_back(rects_[i]);
	}

	if (!this->isUniDirectional())
	{
		frames[nameID_].push_back(std::vector<sf::IntRect>{});
		frames[nameID_][1].clear();
		frames[nameID_][1].reserve(rects_.size() / 2);
		for (size_t i = rects_.size() / 2; i < rects_.size(); i++)
			frames[nameID_][1].emplace_back(rects_[i]);
	}


	sizes[nameID_].push_back(std::vector<sf::Vector2f>{});
	sizes[nameID_][0].clear();
	if (this->isUniDirectional())
	{
		sizes[nameID_][0].reserve(sizes_.size());
		for (size_t i = 0; i < sizes_.size(); i++)
			sizes[nameID_][0].emplace_back(sizes_[i]);
	}
	else
	{
		sizes[nameID_][0].reserve(sizes_.size() / 2);
		for (size_t i = 0; i < sizes_.size() / 2; i++)
			sizes[nameID_][0].emplace_back(sizes_[i]);
	}

	if (!this->isUniDirectional())
	{
		sizes[nameID_].push_back(std::vector<sf::Vector2f>{});
		sizes[nameID_][1].clear();
		sizes[nameID_][1].reserve(sizes_.size() / 2);
		for (size_t i = sizes_.size() / 2; i < sizes_.size(); i++)
			sizes[nameID_][1].emplace_back(sizes_[i]);
	}


	offsets[nameID_].push_back(std::vector<sf::Vector2f>{});
	offsets[nameID_][0].clear();
	if (this->isUniDirectional())
	{
		offsets[nameID_][0].reserve(offsets_.size());
		for (size_t i = 0; i < offsets_.size(); i++)
			offsets[nameID_][0].emplace_back(offsets_[i]);
	}
	else
	{
		offsets[nameID_][0].reserve(offsets_.size() / 2);
		for (int i = 0; i < offsets_.size() / 2; i++)
			offsets[nameID_][0].emplace_back(offsets_[i]);
	}

	if (!this->isUniDirectional())
	{
		offsets[nameID_].push_back(std::vector<sf::Vector2f>{});
		offsets[nameID_][1].clear();
		offsets[nameID_][1].reserve(offsets_.size() / 2);
		for (size_t i = offsets_.size() / 2; i < offsets_.size(); i++)
			offsets[nameID_][1].emplace_back(offsets_[i]);
	}



	delays[nameID_].push_back(std::vector<float>{});
	delays[nameID_][0].clear();
	if (this->isUniDirectional())
	{
		delays[nameID_][0].reserve(delays_.size());
		for (int i = 0; i < delays_.size(); i++)
			delays[nameID_][0].emplace_back(delays_[i]);
	}
	else
	{
		delays[nameID_][0].reserve(delays_.size() / 2);
		for (int i = 0; i < delays_.size() / 2; i++)
			delays[nameID_][0].emplace_back(delays_[i]);
	}

	if (!this->isUniDirectional())
	{
		delays[nameID_].push_back(std::vector<float>{});
		delays[nameID_][1].clear();
		delays[nameID_][1].reserve(delays_.size() / 2);
		for (size_t i = delays_.size() / 2; i < delays_.size(); i++)
			delays[nameID_][1].emplace_back(delays_[i]);
	}




	if (loopDelays.find(nameID_) == loopDelays.end())
		loopDelays[nameID_] = loopDelay_;

	if (looping.find(nameID_) == looping.end())
		looping[nameID_] = looping_;

	if (loopWaits.find(nameID_) == loopWaits.end())
		loopWaits[nameID_] = loopWaits_;

	if (texIDs.find(nameID_) == texIDs.end())
	{
		texIDs[nameID_] = texID_;
	}

	playing = true;
	loopElapsed = 0.f;
	animElapsed = 0.f;



	if (loadFirstValue)
	{
		currentAnim = nameID_;
		currentIndex = 0;
		setFacingRight(true);
		setID(texIDs[nameID_]);
	}



}

AnimObj::AnimObj(const std::string& filename)
	: Obj{}
{
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
	int currDir = (this->isFacingRight()) ? 1 : 0;
	return { {0,0},{1,1} }; // frames[currentAnim][currDir][currentIndex];
}

void AnimObj::update(float dt_, sf::RenderWindow& wnd_)
{
	setBase();

	Obj::update(dt_, wnd_);
}

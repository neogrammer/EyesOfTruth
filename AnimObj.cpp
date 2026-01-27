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

AnimObj::AnimObj(std::unordered_map<AnimName, TextureID>& texID_, std::unordered_set<AnimName>& nameID_, std::unordered_map<AnimName, sf::Vector2f>& frameSizes_, 
	std::unordered_map<AnimName, std::vector<sf::Vector2f>>& offsets_, std::unordered_map<AnimName, std::vector<sf::Vector2f>>& sizes_, 
	std::unordered_map<AnimName, std::vector<float>>& delays_, std::unordered_map<AnimName, uint8_t>& startCols_, std::unordered_map<AnimName, uint8_t>& startRows_, 
	std::unordered_map<AnimName, sf::Vector2f> startPxls_, std::unordered_map<AnimName, uint8_t>& pitches_, std::unordered_map<AnimName, uint8_t>& numFrames_,
	sf::Vector2f position_, bool uniDirectional_, std::unordered_map<AnimName, bool> loopWaits_, std::unordered_map<AnimName, float> loopDelays_, std::unordered_map<AnimName, bool> loopings_)
	: animElapsed{0.f}
	, currentAnim{AnimName::None}
	, currentIndex{ 0 }
	, loopElapsed{0.f}
	, playing{true}
{
	for (auto& aname : nameID_)
	{
		// For each animation, setup
		// 
		
		// Texture IDs and other minor parameters
		anims.emplace(aname);
		texIDs[aname] = texID_[aname];
		loopDelays[aname] = loopDelays_[aname];
		loopWaits[aname] = loopWaits_[aname];
		looping[aname] = loopings_[aname];
		setUniDirectional( uniDirectional_ );

		// major params

		// Texture Offsets
		offsets[aname] = std::vector<std::vector<sf::Vector2f>>{};
		offsets[aname].clear();
		if (isUniDirectional())
		{
			offsets[aname].reserve(1);
			offsets[aname].emplace_back(std::vector<sf::Vector2f>{});
			offsets[aname].back().clear();
			offsets[aname].back().reserve(offsets_[aname].size());
			for (int j = 0; j < offsets_[aname].size() / 2; j++)
				offsets[aname][0].emplace_back(offsets_[aname][j]);
		}
		else
		{
			offsets[aname].reserve(2);
			offsets[aname].emplace_back(std::vector<sf::Vector2f>{});
			offsets[aname][0].clear();
			offsets[aname][0].reserve(offsets_[aname].size() / 2);
			offsets[aname].emplace_back(std::vector<sf::Vector2f>{});
			offsets[aname][1].clear();
			offsets[aname][1].reserve(offsets_[aname].size() / 2);
			for (int j = 0; j < offsets_[aname].size() / 2; j++)
				offsets[aname][0].emplace_back(offsets_[aname][j]);
			for (int j = offsets_[aname].size() / 2; j < offsets_[aname].size(); j++)
				offsets[aname][1].emplace_back(offsets_[aname][j]);
		}

		// Texture IntRects
		// startPxl is where to start for that animation in the texture in the minimum top left of both x and y, then startCol is the start column of the mini sheet,
		//  which stretches out map<AnimName,FrameSize> sizes * map<AnimName,uint8_t pitch from the startPxl
		//  This give you an inner sprite sheet, and you can have any dimensions and sizes you want, for giant texture atlases
		auto stPxl = startPxls_[aname];
		auto stCol = startCols_[aname];
		auto stRow = startRows_[aname];
		uint32_t frWidth = frameSizes_[aname].x;
		uint32_t frHeight = frameSizes_[aname].y;
		// = frameSizes_[aname].y;
		auto pitch = pitches_[aname];
		auto numFrames = numFrames_[aname];
		uint32_t numRows = (uint32_t)(numFrames / pitch);

		if (isUniDirectional())
		{
			frames[aname] = std::vector<std::vector<sf::IntRect>>{};
			frames[aname].clear();
			frames[aname].reserve(1);
			frames[aname].emplace_back(std::vector<sf::IntRect>{});
			frames[aname][0].clear();
			frames[aname][0].reserve(offsets_[aname].size());
			int counter = 0;
			for (int k = 0; k < offsets_[aname].size(), (k + stCol) * frWidth + stPxl.x < stPxl.x + (pitch * frWidth); k++)
			{
				frames[aname][0].emplace_back(sf::IntRect{ {(int)(stPxl.x + (k + stCol) * frWidth),(int)stPxl.y}, {(int)frWidth,(int)frHeight} });
				counter++;
			}
			if (counter < numFrames)
			{
				for (int z = 1; z < numRows; z++)
				{
					for (int k = 0; k < pitch, counter < numFrames; k++)
					{
						frames[aname][0].emplace_back(sf::IntRect{ {(int)(stPxl.x + (k * frWidth)),(int)(stPxl.y +(z * frHeight))}, {(int)frWidth,(int)frHeight}});
						counter++;
					}
				}
			}
		}
		else
		{
			frames[aname] = std::vector<std::vector<sf::IntRect>>{};
			frames[aname].clear();
			frames[aname].reserve(2);
			frames[aname].emplace_back(std::vector<sf::IntRect>{});
			frames[aname][0].clear();
			frames[aname][0].reserve(offsets_[aname].size());
			frames[aname].emplace_back(std::vector<sf::IntRect>{});
			frames[aname][1].clear();
			frames[aname][1].reserve(offsets_[aname].size());
			int counter = 0;
			for (int k = 0; k < offsets_[aname].size() / 2, (k + stCol) * frWidth + startPxls_[aname].x < stPxl.x + (pitch * frWidth); k++)
			{
				frames[aname][0].emplace_back(sf::IntRect{ {(int)(stPxl.x + (k + stCol) * frWidth),(int)stPxl.y}, {(int)frWidth,(int)frHeight} });
				counter++;
			}
			if (counter < numFrames)
			{
				for (int z = 1; z < numRows; z++)
				{
					for (int k = 0; k < pitch, counter < numFrames; k++)
					{
						frames[aname][0].emplace_back(sf::IntRect{ {(int)(stPxl.x + (k * frWidth)),(int)(stPxl.y + (z * frHeight))}, {(int)frWidth,(int)frHeight} });
						counter++;
					}
				}
			}
			for (int k = offsets_[aname].size() / 2; k < offsets_[aname].size(), (k + stCol) * frWidth + startPxls_[aname].x < stPxl.x + (pitch * frWidth); k++)
			{
				frames[aname][1].emplace_back(sf::IntRect{ {(int)(stPxl.x + (k + stCol) * frWidth),(int)stPxl.y}, {(int)frWidth,(int)frHeight} });
				counter++;
			}
			if (counter < numFrames)
			{
				for (int z = 1; z < numRows; z++)
				{
					for (int k = 0; k < pitch, counter < numFrames; k++)
					{
						frames[aname][1].emplace_back(sf::IntRect{ {(int)(stPxl.x + (k * frWidth)),(int)(stPxl.y + (z * frHeight))}, {(int)frWidth,(int)frHeight} });
						counter++;
					}
				}
			}

		}


		// ---------------- END OF TEXTURE RECTS

		//  Gameplay Sizes
				// Texture Offsets
		sizes[aname] = std::vector<std::vector<sf::Vector2f>>{};
		sizes[aname].clear();
		if (isUniDirectional())
		{
			sizes[aname].reserve(1);
			sizes[aname].emplace_back(std::vector<sf::Vector2f>{});
			sizes[aname].back().clear();
			sizes[aname].back().reserve(sizes_[aname].size());
			for (int j = 0; j < sizes_[aname].size() / 2; j++)
				sizes[aname][0].emplace_back(sizes_[aname][j]);
		}
		else
		{
			sizes[aname].reserve(2);
			sizes[aname].emplace_back(std::vector<sf::Vector2f>{});
			sizes[aname][0].clear();
			sizes[aname][0].reserve(sizes_[aname].size() / 2);
			sizes[aname].emplace_back(std::vector<sf::Vector2f>{});
			sizes[aname][1].clear();
			sizes[aname][1].reserve(sizes_[aname].size() / 2);
			for (int j = 0; j < sizes_[aname].size() / 2; j++)
				sizes[aname][0].emplace_back(sizes_[aname][j]);
			for (int j = sizes_[aname].size() / 2; j < sizes_[aname].size(); j++)
				sizes[aname][1].emplace_back(sizes_[aname][j]);
		}
		// End of Gameplay Sizes

		//  Animation Frame Delays
				// Texture Offsets
		delays[aname] = std::vector<std::vector<float>>{};
		delays[aname].clear();
		if (isUniDirectional())
		{
			delays[aname].reserve(1);
			delays[aname].emplace_back(std::vector<float>{});
			delays[aname].back().clear();
			delays[aname].back().reserve(delays_[aname].size());
			for (int j = 0; j < delays_[aname].size() / 2; j++)
				delays[aname][0].emplace_back(delays_[aname][j]);
		}
		else
		{
			delays[aname].reserve(2);
			delays[aname].emplace_back(std::vector < float > {});
			delays[aname][0].clear();
			delays[aname][0].reserve(delays_[aname].size() / 2);
			delays[aname].emplace_back(std::vector<float>{});
			delays[aname][1].clear();
			delays[aname][1].reserve(delays_[aname].size() / 2);
			for (int j = 0; j < delays_[aname].size() / 2; j++)
				delays[aname][0].emplace_back(delays_[aname][j]);
			for (int j = delays_[aname].size() / 2; j < delays_[aname].size(); j++)
				delays[aname][1].emplace_back(delays_[aname][j]);
		}
		// End of Animation Frame Delays
		
		if (currentAnim == AnimName::None)
		{
			currentAnim = aname;
		}
	}
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

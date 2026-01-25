#pragma once
#include "Obj.h"
#include <unordered_map>
#include <vector>
#include <array>
#include <unordered_set>
#include <string>

enum class AnimName
{
	Idle,
	None
};

class AnimObj : public Obj
{
	void setBase();

	std::unordered_map<AnimName, std::vector<std::vector<sf::IntRect>>> frames; // AnimName -> [0]->UniDirectional || rightFacing [1]->LeftFacing -> vector of intrects for the frames in the texture image
	std::unordered_map < AnimName, std::vector<std::vector<sf::Vector2f>>> offsets;
	std::unordered_map < AnimName, std::vector<std::vector<sf::Vector2f>>> sizes;
	
	std::unordered_set<AnimName> anims; // anim names

	AnimName currentAnim;
	uint8_t currentIndex;

public:
	AnimObj(const std::string& filename);
	AnimObj(TextureID texID_, sf::IntRect texRect_, bool uniDirectional_ = false, sf::Vector2f position = { 0.f,0.f }, sf::Vector2f size = { 0.f,0.f }, sf::Vector2f offset_ = { 0.f,0.f });	
	~AnimObj();

	sf::IntRect getCurrentFrame();

};
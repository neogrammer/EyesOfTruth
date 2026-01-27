
#include "PlayState.h"
#include "../../AnimObj.h"
#include <core/globals.h>
#include <iostream>

PlayState::PlayState(GameStateMgr* mgr_)
	: GameState(mgr_)
{

	anObject = nullptr;


	anObject = new AnimObj(TextureID::Default, { {0,0},{109,192} }, true, { 300.f,200.f }, { 109.f,192.f }, { 0.f,0.f });

	auto& o = *dynamic_cast<AnimObj*>(anObject);
	std::vector<sf::IntRect> rects;
	std::vector<sf::Vector2f> offsets;
	std::vector<sf::Vector2f> sizes;
	std::vector<float> delays;
	rects.clear();
	offsets.clear();
	sizes.clear();
	delays.clear();
	rects.reserve(9 * 24);
	offsets.reserve(9 * 24);
	sizes.reserve(9 * 24);
	delays.reserve(9 * 24);
	for (int y = 0; y < 24; y++)
		for (int x = 0; x < 9; x++)
		{
			rects.emplace_back(sf::IntRect{ {x * 109, y * 192}, {109, 192} });
			offsets.emplace_back(sf::Vector2f{ 0.f,0.f });
			sizes.emplace_back(sf::Vector2f{ 109.f, 192.f });
			delays.emplace_back(0.13f);
		}
	o.loadAnimation(AnimName::Idle, TextureID::Default, rects, offsets, sizes, delays, true, false, 0.f, true, true);

}

PlayState::~PlayState()
{
	if (anObject)
	{
		delete anObject;
	}
}

void PlayState::processEvent(std::optional<sf::Event>& e_)
{

	if (const auto* keyPressed = e_->getIf<sf::Event::KeyReleased>())
	{
		if (keyPressed->scancode == sf::Keyboard::Scancode::P)
		{
			std::cout << "Key released in PlayState, attempting to pause state!" << std::endl;
			owner->changeState(GameStateType::Pause, false);
		}
	}
}

void PlayState::input()
{
}

void PlayState::update()
{

	// TESTING ANIMOBJ class
	anObject->update(gTime, gWnd);

}

void PlayState::updateLate()
{
}

void PlayState::render()
{
	gWnd.draw(*anObject->sprite());
}





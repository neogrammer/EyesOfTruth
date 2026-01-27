
#include "SplashState.h"
#include <core/globals.h>
#include "PlayState.h"
#include <iostream>
SplashState::SplashState(GameStateMgr* mgr_)
	: GameState(mgr_)
{

}

SplashState::~SplashState()
{
}

void SplashState::processEvent(std::optional<sf::Event>& e_)
{
	if (const auto* keyPressed = e_->getIf<sf::Event::KeyReleased>())
	{
		if (keyPressed->scancode == sf::Keyboard::Scancode::Enter)
		{
			std::cout << "Key released in Splash State, attempting to go to TitleState!" << std::endl;
			owner->changeState(GameStateType::Title, true);
		}
	}
}

void SplashState::input()
{
	
}

void SplashState::update()
{
}

void SplashState::updateLate()
{
}

void SplashState::render()
{
}
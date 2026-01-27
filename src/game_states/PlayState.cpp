
#include "PlayState.h"
#include <core/globals.h>
#include <iostream>

PlayState::PlayState(GameStateMgr* mgr_)
	: GameState(mgr_)
{
}

PlayState::~PlayState()
{
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
}

void PlayState::updateLate()
{
}

void PlayState::render()
{
}





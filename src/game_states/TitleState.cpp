
#include "TitleState.h"
#include <core/globals.h>
#include <iostream>
TitleState::TitleState(GameStateMgr* mgr_)
	: GameState(mgr_)
{

}

TitleState::~TitleState()
{
}

void TitleState::processEvent(std::optional<sf::Event>& e_)
{
	if (const auto* keyPressed = e_->getIf<sf::Event::KeyReleased>())
	{
		if (keyPressed->scancode == sf::Keyboard::Scancode::Enter)
		{
			std::cout << "Key released in TitleState, attemting to go to play state!" << std::endl;
			owner->changeState(GameStateType::Play, true);
		}
	}
}

void TitleState::input()
{
}

void TitleState::update()
{
}

void TitleState::updateLate()
{
}

void TitleState::render()
{
}





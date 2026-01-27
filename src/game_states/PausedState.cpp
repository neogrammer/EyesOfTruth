#include "PausedState.h"
#include <core/globals.h>
#include <iostream>

PausedState::PausedState(GameStateMgr* mgr_)
	: GameState{mgr_}
{
}

PausedState::~PausedState()
{
}

void PausedState::processEvent(std::optional<sf::Event>& e_)
{

	if (const auto* keyPressed = e_->getIf<sf::Event::KeyReleased>())
	{
		if (keyPressed->scancode == sf::Keyboard::Scancode::P)
		{
			std::cout << "Key released in Paused State, attempting to go back to paused state!" << std::endl;
			owner->popTop();
		}
	}
}

void PausedState::input()
{
}

void PausedState::update()
{
}

void PausedState::updateLate()
{
}

void PausedState::render()
{
	gWnd.setView(gWnd.getDefaultView());

	sf::RectangleShape screenOverlay{ sf::Vector2f{(float)gWW, (float)gWH} };

	sf::Text pausedText{ Cfg::fonts.get((int)Cfg::Fonts::Font1) };
	pausedText.setString("Paused");
	pausedText.setCharacterSize(44U);
	pausedText.setPosition({ gWW / 2.f - 88.f, gWH / 2.f - 22.f });
	pausedText.setFillColor(sf::Color::White);
	pausedText.setOutlineColor(sf::Color::Green);
	pausedText.setOutlineThickness(3);

	screenOverlay.setFillColor(sf::Color(0, 0, 0, 50));

	gWnd.draw(screenOverlay);
	gWnd.draw(pausedText);
	gWnd.setView(gameView);


}

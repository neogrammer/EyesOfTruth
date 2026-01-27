#include <core/Game.h>
#include <type_traits>
#include <string>
#include <variant>
#include <string>
#include <functional>
#include <utility>
#include <iostream>
Game::Game()
{

	wndw::CreateWindow("MegamanOne", 640U, 480U);
	
	gWnd.setPosition({ 120, 20 });
	gStateMgr->setGame(this);
}

void Game::render()
{
	gStateMgr->render();
}

void Game::input()
{
	gStateMgr->input();
}

Game::~Game()
{
}

void Game::run()
{

	gTime = frameTimer.restart().asSeconds();


	// game loop
	while (gWnd.isOpen())
	{
		// window events handled here
		while (std::optional event = gWnd.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				gWnd.close();
			if (const auto* keyPressed = event->getIf<sf::Event::KeyReleased>())
			{
				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
					gWnd.close();
				
		
			}
			gStateMgr->processEvent(event);
		}

		// if not closed, update and draw the game as needed
			input();


			update();
			updateLate();



			// now render the screen
			gWnd.clear(sf::Color(47, 147, 247, 255));
			render();
			gWnd.display();


	}
}


void Game::update()
{
	gStateMgr->update();
}

void Game::updateLate()
{
	gStateMgr->updateLate();
}


#include <SFML/Graphics.hpp>
#include "core/Game.h"
#include "core/Cfg.h"
#include "core/globals.h"

int main()
{
	//sf::ContextSettings settings;
	//settings.antiAliasingLevel = 8;
	//sf::RenderWindow wnd{ sf::VideoMode({640U, 480U}, 32U), "EyesOfTruth", sf::Style::None, sf::State::Windowed, settings };

	// TESTING ANIMOBJ class
	//Obj* anObject = nullptr;


	/*anObject = new AnimObj(TextureID::Default, { {0,0},{109,192} }, true, { 300.f,200.f }, { 109.f,192.f }, { 0.f,0.f });
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


	sf::Clock timer;

	while (wnd.isOpen())
	{
		while (const std::optional event = wnd.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				wnd.close();
			if (auto key = event->getIf<sf::Event::KeyReleased>())
				if (key->code == sf::Keyboard::Key::Escape)
					wnd.close();
		}

		anObject->setVel({ 0.f, 0.f });

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			anObject->setVel({ -300.f, 0.f });
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			anObject->setVel({ 300.f, 0.f });

		}

		float timeElapsed = timer.restart().asSeconds();
		o.update(timeElapsed, wnd);


		wnd.clear(sf::Color(47,147,247,255));
		wnd.draw(*o.sprite());
		wnd.display();
	}*/
	Cfg::Initialize();

	Game game;
	game.run();

	return 0;

}
#include <SFML/Graphics.hpp>

void main()
{
	sf::ContextSettings settings;
	settings.antiAliasingLevel = 8;
	sf::RenderWindow wnd{ sf::VideoMode({1600U, 900U}, 32U), "EyesOfTruth", sf::State::Windowed, settings };

	while (wnd.isOpen())
	{
		while (const std::optional event = wnd.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				wnd.close();
		}

		wnd.clear();
		
		wnd.display();
	}


}
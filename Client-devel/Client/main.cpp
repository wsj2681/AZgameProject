#include <iostream>
#include "SFML/Graphics.hpp"



int main()
{
	std::cout << "clear";
	sf::RenderWindow window(sf::VideoMode(400, 400), "SFML");

	sf::CircleShape circle(200.f);
	circle.setFillColor(sf::Color::Green);


	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		window.draw(circle);
		window.display();
	}
}
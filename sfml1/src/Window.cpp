#include "window.h"

Game g;

void Window::loop(sf::RenderWindow& w)
{
	while (w.isOpen())
	{
		g.init();
		sf::Event event;
		while (w.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				w.close();
		}
		w.clear(sf::Color(250, 220, 100, 0));

		g.show(w);
		w.display();
		g.input_player();
		Sleep(60);
	}
}
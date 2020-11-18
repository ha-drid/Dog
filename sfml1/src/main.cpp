#include <iostream>
#include <stdexcept>

#include <SFML/Graphics.hpp>

#include "window.h"
#include "size.h"


int main()
{
	try
	{
		setlocale(LC_ALL, "ru");

		sf::ContextSettings setting;
		setting.antialiasingLevel = 8;

		sf::RenderWindow sfWindow(sf::VideoMode(Width, Height), "Dog", sf::Style::Default, setting);
		Window w;

		w.loop(sfWindow);
	}
	catch(std::runtime_error& e)
	{
		std::cout << "Except" << e.what() << std::endl;
		return -1;
	}
	return 0;
}
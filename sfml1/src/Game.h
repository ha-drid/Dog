#pragma once
#include <SFML/Graphics.hpp>
#include <conio.h>
#include <memory>
#include <iostream>
#include <ctime>

#include "Cell.h"
#include "Object.h"
#include "size.h"

static const int Width_Map = 20;
static const int Height_Map = 10;

class Game
{
public:
	Game();
	void init();
	void show(sf::RenderWindow& w);
	void input_player();
	~Game();
private:
	Cell map[Height_Map][Width_Map];
	Object player;
	Object food;
	int T;
};


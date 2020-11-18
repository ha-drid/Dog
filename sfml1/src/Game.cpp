#include "Game.h"

Game::Game()
{
	player.x = Width_Map / 2;
	player.y = Height_Map / 2;

	T = 0;
	food.x = 5;
	food.y = 7;
}

void Game::init()
{	
	for(int i = 0;i < Height_Map;++i)
		for (int n = 0; n < Width_Map; ++n) {
			map[i][n].isBaricade = false;
			map[i][n].isFood = false;
			map[i][n].isPlayer = false;
		}

	for (int i = 0; i < Width_Map; ++i)
		map[0][i].isBaricade = true;

	for (int i = 0; i < Height_Map; ++i)
	{
		map[i][0].isBaricade = true;
		map[i][Width_Map - 1].isBaricade = true;
	}

	for (int i = 0; i < Width_Map; ++i)
		map[Height_Map - 1][i].isBaricade = true;

	map[food.y][food.x].isFood = true;
	map[player.y][player.x].isPlayer = true;
}

void Game::show(sf::RenderWindow& w)
{
	sf::RectangleShape rect(sf::Vector2f(Width / Width_Map, Height / Height_Map));

	system("cls");
	std::cout << "—чет: " << T << std::endl;

	for (int i = 0; i < Height_Map; ++i) {
		for (int n = 0; n < Width_Map; ++n) {

			rect.setPosition(n * (Width / Width_Map), i * (Height / Height_Map));
			if (map[i][n].isBaricade) {
				rect.setFillColor(sf::Color(255, 75, 75));
			}
			else if (map[i][n].isPlayer) {
				rect.setFillColor(sf::Color(100, 100, 100));
			}
			else if(map[i][n].isFood) {
				rect.setFillColor(sf::Color(50, 255, 50));
			}
			else {
				if ((i + n) % 2 == 0)
					rect.setFillColor(sf::Color(195, 200, 255));
				else
					rect.setFillColor(sf::Color(143, 200, 195));
			}
			w.draw(rect);
		}
	}
}

void Game::input_player()
{
	std::shared_ptr<int> key(new int());

	

	int iX = player.x;
	int iY = player.y;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) --player.y;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) --player.y;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) ++player.y;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) ++player.y;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) ++player.x;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) ++player.x;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) --player.x;
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) --player.x;


	if (map[player.y][player.x].isBaricade) {
		player.x = iX;
		player.y = iY;
	}

	srand(time(NULL));
	if ((player.y == food.y) && (player.x == food.x))
	{
		food.y = (rand() % (Height_Map - 2)) + 1;
		food.x = (rand() % (Width_Map - 2)) + 1;
		++T;
	}
}

Game::~Game()
{
}

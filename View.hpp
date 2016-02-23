#pragma once

#include <SFML/Graphics.hpp>

#include "Model.hpp"
#include "TileMap.hpp"

class View
{
public:
	View(Model* m);
	~View();

	Model* model;

	void render();

	sf::RenderWindow window;

	TileMap map;

	sf::RectangleShape player;

	sf::RectangleShape car;
};
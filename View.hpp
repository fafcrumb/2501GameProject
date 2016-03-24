#pragma once

#include <SFML/Graphics.hpp>

#include "Model.hpp"
#include "Renderable.hpp"
#include "TileMap.hpp"

class Model;

class View
{
public:
	View(Model* m);
	~View();

	Model* model;

	sf::RenderWindow window;

	void render();

	TileMap map;
	TileMap backgroundMap;

	std::vector<Renderable*> gameViewElements;
	std::vector<Renderable*> minimapElements;
	std::vector<Renderable*> hudElements;

	sf::View gameView;
	sf::View minimapView;
	sf::View hudView;
};
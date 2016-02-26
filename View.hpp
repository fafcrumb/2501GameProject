#pragma once

#include <SFML/Graphics.hpp>

#include "Renderable.hpp"
#include "Model.hpp"
#include "TileMap.hpp"

class Model;

class View
{
public:
	View(Model* m);
	~View();

	Model* model;

	void render();

	sf::RenderWindow window;

	TileMap map;

	std::vector<Renderable*> renderables;
};
#pragma once

#include <SFML/Graphics.hpp>

#include "Model.hpp"
#include "View.hpp"
#include "Controller.hpp"

class Game
{
public:
	Game();
	~Game();

	Model* model;
	View* view;
	Controller* controller;

	void loop();

	sf::Clock clock;
	sf::Time deltaTime;
};
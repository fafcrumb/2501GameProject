#include "View.hpp"
#include <iostream>
View::View(Model* m)
{
	this->model = m;

	//1280, 1024
	//640, 640
	//225, 225
	window.create(sf::VideoMode(225, 225), "Assignment 3");
	window.setFramerateLimit(60);

	//Map
	map.load("Assets/tileset.jpg", sf::Vector2u(32, 32), model->cameraTiles, model->cameraWidth, model->cameraHeight);

	//Player
	player.setSize(sf::Vector2f(32, 32));
	player.setOrigin(sf::Vector2f(16, 16));
	player.setFillColor(sf::Color::Red);
	player.setPosition(sf::Vector2f(model->playerX, model->playerY));

	//Car
	car.setSize(sf::Vector2f(22, 10));
	car.setOrigin(sf::Vector2f(11, 5));
	car.setFillColor(sf::Color::Blue);
	car.setPosition(sf::Vector2f(model->carLocation.x - model->cameraX, model->carLocation.y - model->cameraY));
}

View::~View()
{}

void View::render()
{
	window.clear();

	//Map
	map.setPosition(sf::Vector2f(-(int)model->cameraX % 32, -(int)model->cameraY % 32));
	map.load("Assets/tileset.jpg", sf::Vector2u(32, 32), model->cameraTiles, model->cameraWidth, model->cameraHeight);
	window.draw(map);

	//Player
	player.setPosition(sf::Vector2f(model->playerX - model->cameraX, model->playerY - model->cameraY));
	window.draw(player);

	//Car
	float PI = 3.14159265;
	car.setPosition(sf::Vector2f(model->carLocation.x - model->cameraX, model->carLocation.y - model->cameraY));
	car.setRotation(model->carHeading * 180 / PI);
	window.draw(car);

	window.display();


	//Optional console based grid view (set framerate to 2 or 3 when using)
	/*for (int i = 0; i < model->mapHeight; i++)
	{
		for (int j = 0; j < model->mapWidth; j++)
		{
			if (model->playerCol == j && model->playerRow == i)
				std::cout << "$" << " ";
			else if (model->cameraCol == j && model->cameraRow == i)
				std::cout << "*" << " ";
			else if (model->carCol == j && model->carRow == i)
				std::cout << "=" << " ";
			else
				std::cout << model->mapTiles[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "\n\n\n\n";*/
}

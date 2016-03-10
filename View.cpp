#include "View.hpp"
#include <iostream>

View::View(Model* m)
{
	this->model = m;

	window.create(sf::VideoMode(225, 225), "Progress Report");
	window.setFramerateLimit(60);

	map.loadTexture("Assets/tileset.jpg");
	map.loadTiles(sf::Vector2u(32, 32), model->camera->getTiles(), model->camera->getWidth(), model->camera->getHeight());

	renderables.push_back(model->player);
	renderables.push_back(model->truck);
	renderables.push_back(model->speedometer);
	renderables.push_back(model->timeDisplay);
}

View::~View()
{}

void View::render()
{
	window.clear();

	map.setPosition(sf::Vector2f(-(int)model->camera->getX() % 32, -(int)model->camera->getY() % 32));
	map.loadTiles(sf::Vector2u(32, 32), model->camera->getTiles(), model->camera->getWidth(), model->camera->getHeight());
	window.draw(map);

	for (Renderable* object : renderables)
		object->render(this);

	window.display();

	//Optional console based grid view (set framerate to 2 or 3 when using)
	/*
	for (int i = 0; i < model->mapHeight; i++)
	{
		for (int j = 0; j < model->mapWidth; j++)
		{
			if (model->player->getCol() == j && model->player->getRow() == i)
				std::cout << "$" << " ";
			else if (model->camera->getCol() == j && model->camera->getRow() == i)
				std::cout << "*" << " ";
			else if (model->truck->getCol() == j && model->truck->getRow() == i)
				std::cout << "=" << " ";
			else
				std::cout << model->mapTiles[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "\n\n\n\n";
	*/
}

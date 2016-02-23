#include "Controller.hpp"

Controller::Controller(Model* m, View* v)
{
	this->model = m;
	this->view = v;
}

Controller::~Controller()
{}

void Controller::inputs()
{
	sf::Event event;

	while (view->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			view->window.close();
			break;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		model->playerY -= model->playerSpeed;
		model->carSpeed += 10;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		model->playerY += model->playerSpeed;
		model->carSpeed -= 10;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		model->playerX -= model->playerSpeed;
		model->steerAngle -= 0.01;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		model->playerX += model->playerSpeed;
		model->steerAngle += 0.01;
	}
}
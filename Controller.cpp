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
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Space) //switch movement/camera between player and car with SPACE (for demo purposes)
				model->inTruck = !model->inTruck;
			break;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if(!model->inTruck)
			model->player->moveUp();
		else
			model->truck->speedUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if(!model->inTruck)
			model->player->moveDown();
		else
			model->truck->speedDown();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if(!model->inTruck)
			model->player->moveLeft();
		else
			model->truck->steerLeft();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if(!model->inTruck)
			model->player->moveRight();
		else
			model->truck->steerRight();
	}
	else
	{
		if(model->inTruck)
			model->truck->steerStraight();
	}
}
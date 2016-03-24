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
			if (event.key.code == sf::Keyboard::E) 
			{
				if (model->player->inVehicle)
					model->player->exitVehicle(model->truck->getLocation());
				else
					model->player->interact(model->truck->getLocation(), model->deliveryManager);
			}
			if (event.key.code == sf::Keyboard::I)
			{
				model->inventory->open();
			}
			break;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (model->player->inVehicle)
			model->truck->boost();
	}
	else
	{
		if (model->player->inVehicle)
			model->truck->boostOver();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (!model->player->inVehicle)
			model->player->moveUp();
		else
			model->truck->speedUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (!model->player->inVehicle)
			model->player->moveDown();
		else
			model->truck->speedDown();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (!model->player->inVehicle)
			model->player->moveLeft();
		else
			model->truck->steerLeft();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (!model->player->inVehicle)
			model->player->moveRight();
		else
			model->truck->steerRight();
	}
	else
	{
		if (model->player->inVehicle)
			model->truck->steerStraight();
	}
}

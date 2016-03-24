#include "Game.hpp"
#include <iostream>
Game::Game()
{
	this->model = new Model;
	this->view = new View(model);
	this->controller = new Controller(model, view);
}

Game::~Game()
{ }

void Game::loop()
{
	while (this->view->window.isOpen())
	{
		deltaTime = clock.restart();
		this->controller->inputs();
		this->model->update(deltaTime);
		this->view->render();
	}
}
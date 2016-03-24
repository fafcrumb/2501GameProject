#include "View.hpp"
#include <iostream>

View::View(Model* m)
{
	this->model = m;
	//1300, 780
	window.create(sf::VideoMode(1300, 780), "Assignment 3");
	window.setFramerateLimit(60);

	map.loadTexture("Assets/CityTiles.png");
	//map.loadTiles(sf::Vector2u(130, 130), model->camera->getTiles(), model->camera->getWidth(), model->camera->getHeight());
	map.loadTiles(sf::Vector2u(130, 130), model->tiles, model->mapWidth, model->mapHeight);

	backgroundMap.loadTexture("Assets/CityTiles.png");
	int size = model->camera->getWidth() * model->camera->getHeight();
	int *grassTiles = new int[size];
	for (int i = 0; i < size; i++)
		grassTiles[i] = 0;
	backgroundMap.loadTiles(sf::Vector2u(130, 130), grassTiles, model->camera->getWidth(), model->camera->getHeight());
	
	gameViewElements.push_back(model->truck);
	gameViewElements.push_back(model->player);
	gameViewElements.push_back(model->deliveryManager);

	hudElements.push_back(model->speedometer);
	hudElements.push_back(model->inventory);

	gameView = window.getDefaultView();
	gameView.setCenter(model->camera->getCenter());
	gameView.zoom(1.f);
	gameView.setViewport(sf::FloatRect(0, 0, 1, 1));

	minimapView = window.getDefaultView();
	minimapView.setCenter(model->mapWidth/2 * 130, model->mapHeight/2 * 130);
	minimapView.zoom(4.5f);
	minimapView.setViewport(sf::FloatRect(0.75f, 0, 0.25f, 0.25f));

	hudView = window.getDefaultView();
	hudView.zoom(1.f);
}

View::~View()
{}

void View::render()
{
	window.clear();

	window.setView(gameView);
	gameView.setCenter(model->camera->getCenter());
	window.draw(map);
	for (Renderable* object : gameViewElements)
		object->render(this);

	window.setView(minimapView);
	window.draw(map);
	for (Renderable* object : gameViewElements)
		object->render(this);
	
	window.setView(hudView);
	for (Renderable* object : hudElements)
		object->render(this);

	window.display();
}
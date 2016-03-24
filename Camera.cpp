#include "Camera.hpp"
#include <iostream>
Camera::Camera(int **mapTiles, int mapWidth, int mapHeight, int truckCol, int truckRow)
{
	width = 10;
	height = 6;
	col = truckCol - width / 2;
	row = truckRow - height / 2;
	x = y = 0.f;

	//Visible tiles to load into tilemap class
	/*tiles = new int[(width) * (height)];
	int k = 0;
	for (int i = row; i < row + height; i++)
		for (int j = col; j < col + width; j++)
		{
			if (i < 0 || j < 0 || i > mapHeight - 1 || j > mapWidth - 1)
				tiles[k] = 0;
			else
				tiles[k] = mapTiles[i][j];
			k++;
		}*/
}

Camera::~Camera()
{}

void Camera::update(Model* model, sf::Time deltaTime)
{
	if (model->player->inVehicle)
	{
		x = model->truck->getLocation().x - width / 2 * 130;
		y = model->truck->getLocation().y - height / 2 * 130;
	}
	else
	{
		x = model->player->getX() - width / 2 * 130;
		y = model->player->getY() - height / 2 * 130;
	}

	if (x + width * 130 >= model->mapWidth * 130)
		x = (float)model->mapWidth * 130 - width * 130;
	if (x <= 0)
		x = 0;
	if (y + height * 130 >= model->mapHeight * 130)
		y = (float)model->mapHeight * 130 - height * 130;
	if (y <= 0)
		y = 0;	

	col = (int)x / 130;
	row = (int)y / 130;

	//Reset camera's tiles
/*	int k = 0;
	for (int i = row; i < row + height; i++)
		for (int j = col; j < col + width; j++)
		{
			if (i < 0 || j < 0 || i > model->mapHeight - 1 || j > model->mapWidth - 1)
				tiles[k] = 0;
			else
				tiles[k] = model->mapTiles[i][j];
			k++;
		}*/
}

float Camera::getX() { return x; }

float Camera::getY() { return y; }

int Camera::getWidth() { return width; }

int Camera::getHeight() { return height; }

int Camera::getCol() { return col; }

int Camera::getRow() { return row; }

int* Camera::getTiles() { return tiles; }

sf::Vector2f Camera::getCenter()
{
	return sf::Vector2f(x + width / 2 * 130, y + height / 2 * 130);
}

#include "Camera.hpp"

Camera::Camera(Tile*** mapTiles)
{
	width = height = 8;
	col = row = 0;
	x = y = 0.f;

	//Visible tiles to load into tilemap class
	int k = 0;
	tiles = new Tile*[height * width];
	for (int i = row; i < row + height; i++)
		for (int j = col; j < col + width; j++)
		{
			tiles[k] = mapTiles[i][j];
			k++;
		}
}

Camera::~Camera()
{}

void Camera::update(Model* model, sf::Time deltaTime)
{
	//Camera follows player
	if (model->inTruck)
	{
		x = model->truck->getLocation().x - 112.f;
		y = model->truck->getLocation().y - 112.f;
	}
	else
	{
		x = model->player->getX() - 112.f;
		y = model->player->getY() - 112.f;
	}

	//Camera bounds
	if (x + width * 32 >= model->mapWidth * 32)
		x = (float)model->mapWidth * 32 - width * 32;
	if (x <= 0)
		x = 0;
	if (y + height * 32 >= model->mapHeight * 32)
		y = (float)model->mapHeight * 32 - height * 32;
	if (y <= 0)
		y = 0;

	col = (int)x / 32;
	row = (int)y / 32;

	//Reset camera's tiles
	int k = 0;
	for (int i = row; i < row + height; i++)
		for (int j = col; j < col + width; j++)
		{
			tiles[k] = model->tileProperties[i][j];
			k++;
		}
}

float Camera::getX() { return x; }

float Camera::getY() { return y; }

int Camera::getWidth() { return width; }

int Camera::getHeight() { return height; }

int Camera::getCol() { return col; }

int Camera::getRow() { return row; }

Tile** Camera::getTiles() { return tiles; }




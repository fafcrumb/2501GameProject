#pragma once

#include "Model.hpp"

class Camera : public Updateable
{
public:
	Camera(int**, int, int, int, int);
	~Camera();
	void update(Model*, sf::Time);
	float getX(); float getY();
	int getWidth(); int getHeight();
	int getCol(); int getRow();
	int* getTiles();
	sf::Vector2f getCenter();

	float offsetY = 0;
	float offsetX = 0;
private:
	int width, height;
	int col, row;
	float x, y;
	int *tiles;
};
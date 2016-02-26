#pragma once

#include "Model.hpp"

class Camera : public Updateable
{
public:
	Camera(int**);
	~Camera();
	void update(Model*, sf::Time);
	float getX(); float getY();
	int getWidth(); int getHeight();
	int getCol(); int getRow();
	int* getTiles();
private:
	int width, height;
	int col, row;
	float x, y;
	int *tiles;
};

#pragma once

#include "Model.hpp"
#include "Tile.hpp"

class Camera : public Updateable
{
public:
	Camera(Tile***);
	~Camera();
	void update(Model*, sf::Time);
	float getX(); float getY();
	int getWidth(); int getHeight();
	int getCol(); int getRow();
	Tile** getTiles();
private:
	int width, height;
	int col, row;
	float x, y;
	Tile **tiles;
};

#pragma once
//Included new Tile class header as well as changed data types and functions related to the int array for the map to a Tile array
#include "Model.hpp"
#include "Tile.hpp"

class Camera : public Updateable
{
public:
	Camera(Tile***); // Change
	~Camera();
	void update(Model*, sf::Time);
	float getX(); float getY();
	int getWidth(); int getHeight();
	int getCol(); int getRow();
	Tile** getTiles(); // change
private:
	int width, height;
	int col, row;
	float x, y;
	Tile **tiles; // Change
};

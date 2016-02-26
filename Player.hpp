#pragma once

#include <SFML/Graphics.hpp>

#include "Model.hpp"
#include "View.hpp"

class Model;
class View;

class Player : public Updateable, public Renderable
{
public:
	Player();
	~Player();
	void update(Model*, sf::Time);
	void render(View*);
	void moveUp(); void moveDown();
	void moveLeft(); void moveRight();
	float getX() { return x; };
	float getY() { return y; };
	int getCol() { return col; }
	int getRow() { return row; }

private:
	int col, row;
	float x, y;
	int speed;
	sf::RectangleShape rect;
};
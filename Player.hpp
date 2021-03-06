#pragma once

#include <SFML/Graphics.hpp>

#include "Model.hpp"
#include "View.hpp"
#include "Renderable.hpp"
#include "DeliveryManager.hpp"

class Model;
class View;
class DeliveryManager;

class Player : public Updateable, public Renderable
{
public:
	Player();
	~Player();
	void update(Model*, sf::Time);
	void render(View*);
	void moveUp(); void moveDown();
	void moveLeft(); void moveRight();

	void interact(sf::Vector2f, DeliveryManager*);
	void enterVehicle();
	void exitVehicle(sf::Vector2f);

	bool inVehicle = false;

	float getX() { return x; };
	float getY() { return y; };
	int getCol() { return col; }
	int getRow() { return row; }

private:
	int col, row;
	float x, y;
	int speed;
	float size;
	int yMove;
	int xMove;

	sf::Image playerImage;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
};

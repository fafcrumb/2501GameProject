#pragma once

#include <SFML/Graphics.hpp>

#include "Model.hpp"
#include "View.hpp"
#include "Renderable.hpp"

#define PI 3.14159265f

class DeliveryTruck : public Updateable, public Renderable
{
public:
	DeliveryTruck();
	~DeliveryTruck();
	void update(Model*, sf::Time deltaTime);
	void render(View*);
	void speedUp(); void speedDown();
	void steerLeft(); void steerRight(); void steerStraight();
	sf::Vector2f getLocation() { return location; }
	float getHeading() { return heading; }
	int getCol() { return col; }
	int getRow() { return row; }
	float getSpeed() { return speed; }

private:
	int col, row;
	sf::Vector2f location;
	float heading;
	float speed;
	float steerAngle;
	float wheelBase; // the distance between the two axles
	sf::Texture texture;
	sf::Sprite car;
};
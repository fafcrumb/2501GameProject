#include "DeliveryTruck.hpp"


DeliveryTruck::DeliveryTruck()
{
	col = 6;
	row = 6;
	location = sf::Vector2f(130.f * col, 130.f * row);
	heading = -90 * PI / 180;
	speed = steerAngle = 0;
	wheelBase = 130;
	maxSpeed = 400;

	texture.loadFromFile("Assets/car_green_1.png");
	texture.setSmooth(true);
	car.setTexture(texture);
	car.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	car.setRotation(heading * 180 / PI);
	moveTest.setSize(sf::Vector2f(71, 131));
	moveTest.setOrigin(sf::Vector2f(71 / 2.f, 131 / 2.f));
	moveTest.setPosition(sf::Vector2f(location.x, location.y));
}

DeliveryTruck::~DeliveryTruck()
{}

void DeliveryTruck::update(Model* model, sf::Time deltaTime)
{
	//Max speed
	if (abs(speed) > maxSpeed)
	{
		if (speed < 0)
			speed = -maxSpeed;
		else
			speed = maxSpeed;
	}

	//Friction
	if (speed > 0)
	{
		speed -= 5;
		if (speed < 0)
			speed = 0;
	}
	else
	{
		speed += 5;
		if (speed > 0)
			speed = 0;
	}

	//Main car logic
	//Source: http://engineeringdotnet.blogspot.com/2010/04/simple-2d-car-physics-in-games.html

	sf::Vector2f frontWheel = location + wheelBase / 2 * sf::Vector2f(cos(heading), sin(heading));
	sf::Vector2f backWheel = location - wheelBase / 2 * sf::Vector2f(cos(heading), sin(heading));

	backWheel += speed * deltaTime.asSeconds() * sf::Vector2f(cos(heading), sin(heading));
	frontWheel += speed * deltaTime.asSeconds() * sf::Vector2f(cos(heading + steerAngle), sin(heading + steerAngle));
	moveTest.setPosition((frontWheel + backWheel) / 2.f);
	moveTest.setRotation(atan2(frontWheel.y - backWheel.y, frontWheel.x - backWheel.x) * 180 / PI + 90);
	sf::Vector2f projected = moveTest.getPosition();
	float tempColFront = frontWheel.x / 130;
	float tempRowFront = frontWheel.y / 130;
	float tempColBack = backWheel.x / 130;
	float tempRowBack = backWheel.y / 130;

	sf::Vector2u collision = model->collidingWithBuilding(moveTest.getGlobalBounds());
	if (collision.x == 100) {
		if (tempColFront >= 0.01 && tempColFront <= model->mapWidth - 0.01 && tempColBack >= 0.01 && tempColBack <= model->mapWidth - 0.01 && tempRowFront >= 0.01 && tempRowFront <= model->mapHeight - 0.01 && tempRowBack >= 0.01 && tempRowBack <= model->mapHeight - 0.01)
		{
			location = (frontWheel + backWheel) / 2.f;
			heading = atan2(frontWheel.y - backWheel.y, frontWheel.x - backWheel.x);
			moveTest.setRotation(heading * 180 / PI + 90);
		}
		else {
			moveTest.setPosition(location);
			moveTest.setRotation(heading * 180 / PI + 90);
		}
	}
	else {
		moveTest.setPosition(location);
		moveTest.setRotation(heading * 180 / PI + 90);
	}

	col = (int)location.x / 130;
	row = (int)location.y / 130;
}

void DeliveryTruck::render(View* view)
{
	car.setPosition(sf::Vector2f(location.x, location.y));
	car.setRotation(heading * 180 / PI + 90);
	view->window.draw(car);
}

void DeliveryTruck::speedUp() { speed += 30; }

void DeliveryTruck::speedDown() { speed -= 30; }

void DeliveryTruck::steerLeft() { steerAngle = -0.5; }

void DeliveryTruck::steerRight() { steerAngle = 0.5; }

void DeliveryTruck::steerStraight() { steerAngle = 0; }

void DeliveryTruck::boost() { maxSpeed = 700; }

void DeliveryTruck::boostOver() 
{
	if (maxSpeed > 400)
	{
		maxSpeed -= 5;
	}
}

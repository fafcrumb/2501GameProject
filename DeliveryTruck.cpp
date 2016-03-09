#include "DeliveryTruck.hpp"

DeliveryTruck::DeliveryTruck()
{
	col = row = 5;
	location = sf::Vector2f(144, 144);
	heading = speed = steerAngle = 0;
	wheelBase = 32;

	rect.setSize(sf::Vector2f(32, 10));
	rect.setOrigin(sf::Vector2f(16, 5));
	rect.setFillColor(sf::Color::Blue);
}

DeliveryTruck::~DeliveryTruck()
{}

void DeliveryTruck::update(Model* model, sf::Time deltaTime)
{
	//Max speed
	if (abs(speed) > 200)
	{
		if (speed < 0)
			speed = -200;
		else
			speed = 200;
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

	int tempColFront = (int)frontWheel.x / 32;
	int tempRowFront = (int)frontWheel.y / 32;
	int tempColBack = (int)backWheel.x / 32;
	int tempRowBack = (int)backWheel.y / 32;

	if (model->tileProperties[tempRowFront][tempColFront]->returnBlockable() == 0 && model->tileProperties[tempRowBack][tempColBack]->returnBlockable() == 0) {

		location = (frontWheel + backWheel) / 2.f;
		heading = atan2(frontWheel.y - backWheel.y, frontWheel.x - backWheel.x);


		col = (int)location.x / 32;
		row = (int)location.y / 32;
	}
	else
		speed = 0;
}

void DeliveryTruck::render(View* view)
{
	rect.setPosition(sf::Vector2f(location.x - view->model->camera->getX(), location.y - view->model->camera->getY()));
	rect.setRotation(heading * 180 / PI);
	view->window.draw(rect);
}

void DeliveryTruck::speedUp() { speed += 15; }

void DeliveryTruck::speedDown() { speed -= 15; }

void DeliveryTruck::steerLeft() { steerAngle = -0.5; }

void DeliveryTruck::steerRight() { steerAngle = 0.5; }

void DeliveryTruck::steerStraight() { steerAngle = 0; }

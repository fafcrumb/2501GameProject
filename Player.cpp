#include "Player.hpp"
#include <iostream>
Player::Player()
{
	col = 6;
	row = 6;
	size = 35.f;
	x = y = 130 * (float)row + size/2;
	speed = 3;

	playerImage.loadFromFile("Assets/actor.png");
	playerImage.createMaskFromColor(sf::Color::White);
	playerTexture.loadFromImage(playerImage);
	playerTexture.setSmooth(true);
	playerSprite.setTexture(playerTexture);
	playerSprite.setPosition(sf::Vector2f(x, y));
	playerSprite.setOrigin(sf::Vector2f(32, 32));
}

Player::~Player()
{}

void Player::update(Model* model, sf::Time deltaTime)
{
	//Player bounds
	if (x + size / 2 >= (model->mapWidth) * 130)
		x = (float)(model->mapWidth) * 130 - size / 2;
	if (x - size / 2 <= 0)
		x = size / 2.f;
	if (y + size / 2 >= (model->mapHeight) * 130)
		y = (float)(model->mapHeight) * 130 - size / 2;
	if (y - size / 2 <= 0)
		y = size / 2.f;

	if (model->collidingWithBuilding(playerSprite.getGlobalBounds()))
	{
		std::cout << "COLLIDING!" << std::endl;
	}

	col = (int)x / 130;
	row = (int)y / 130;
}

void Player::render(View* view)
{
	playerSprite.setPosition(sf::Vector2f(x, y));
	if (!inVehicle)
		view->window.draw(playerSprite);
}

void Player::moveUp() { y -= speed; }

void Player::moveDown() { y += speed; }

void Player::moveLeft() { x -= speed; }

void Player::moveRight() { x += speed; }

void Player::interact(sf::Vector2f vehicleLocation, DeliveryManager* deliveryManager)
{
	sf::Vector2u playerPoint(col, row);
	Delivery* delivery = deliveryManager->getDeliveryAt(playerPoint);
	if (delivery != NULL) {
		if (delivery->getPickupPoint() == playerPoint && !delivery->isPickedUp()) {
			deliveryManager->pickupDelivery(delivery);
		}
		else if (delivery->getDropoffPoint() == playerPoint && delivery->isPickedUp())
			deliveryManager->dropoffDelivery(delivery);
	}
	else if (abs(x - vehicleLocation.x) < 80 && abs(y - vehicleLocation.y) < 80)
		enterVehicle();
}

void Player::enterVehicle()
{
	inVehicle = true;
}

void Player::exitVehicle(sf::Vector2f vehicleLocation)
{
	inVehicle = false;
	x = vehicleLocation.x - 50;
	y = vehicleLocation.y - 50;
}

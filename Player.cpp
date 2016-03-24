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
	sf::Vector2u collision = model->collidingWithBuilding(rect.getGlobalBounds());
	if (collision.x != 100)
	{
		if (yMove > 0 && collision.y > row) {
			y = y - (y - collision.y * 130) - size/2 - 1;
			std::cout << "FFF" << std::endl;
		}
		else if (yMove < 0  && collision.y < row) {
			y = y + ((collision.y * 130 + 130) - y) + size/2 + 1;
		}
		if (xMove > 0  && collision.x > col) {
			x = x - (x - collision.x * 130) - size/2 - 1;
		}
		else if (xMove < 0 && collision.x < col) {
			x = x + ((collision.x * 130 + 130) - x) + size/2 + 1;
		}
	}
	yMove = 0;
	xMove = 0;

	col = (int)x / 130;
	row = (int)y / 130;
}

void Player::render(View* view)
{
	playerSprite.setPosition(sf::Vector2f(x, y));
	if (!inVehicle)
		view->window.draw(playerSprite);
}

void Player::moveUp() { 
	y -= speed; 
	yMove = -1;
}

void Player::moveDown() { 
	y += speed; 
	yMove = 1;
}

void Player::moveLeft() { 
	x -= speed; 
	xMove = -1;
}

void Player::moveRight() { 
	x += speed; 
	xMove = 1;
}

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

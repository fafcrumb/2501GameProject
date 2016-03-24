#include "Delivery.hpp"

Delivery::Delivery(std::string itemName, std::string imageFile, sf::Vector2u pickupPoint, sf::Vector2u dropoffPoint, sf::Time timeLimit)
{
	this->itemName = itemName;
	this->imageFile = imageFile;
	this->timeLimit = timeLimit;
	this->pickupPoint = pickupPoint;
	this->dropoffPoint = dropoffPoint;
	pickedUp = droppedOff = false;
}

Delivery::~Delivery()
{}

bool Delivery::checkExpired(sf::Time deliveryTimer)
{
	if (deliveryTimer > timeLimit)
		return true;
	return false;
}

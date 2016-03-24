#pragma once

#include <SFML/Graphics.hpp>

class Delivery
{
public:
	Delivery(std::string, std::string, sf::Vector2u, sf::Vector2u, sf::Time);
	~Delivery();
	bool checkExpired(sf::Time);
	sf::Vector2u getPickupPoint() { return pickupPoint; }
	sf::Vector2u getDropoffPoint() { return dropoffPoint; }
	sf::Color getColor() { return color; }
	std::string getImageFile() { return imageFile; }
	void pickUp() { pickedUp = true; }
	bool isPickedUp() { return pickedUp; }
	void dropOff() { droppedOff = true; }
	bool isDroppedOff() { return droppedOff; }
	void miniChange() { miniMe = !miniMe; }
	bool getMiniMe() { return miniMe; }
private:
	std::string itemName;
	std::string imageFile;
	sf::Vector2u pickupPoint;
	sf::Vector2u dropoffPoint;
	sf::Time timeLimit;
	sf::Color color;
	bool pickedUp;
	bool droppedOff;
	bool miniMe;
};

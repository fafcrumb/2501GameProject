#include "DeliveryManager.hpp"
#include <iostream>
DeliveryManager::DeliveryManager(std::vector<sf::Vector2u> allSidewalkTiles)
{
	pickupMan.setFillColor(sf::Color::Blue);
	pickupMan.setRadius(20);

	dropOffMan.setFillColor(sf::Color::Cyan);
	dropOffMan.setRadius(20);

	availableTiles = allSidewalkTiles;

	minDistance = 10.f;
	spawnInterval = 15;

	srand(time(NULL));
}

DeliveryManager::~DeliveryManager()
{}

void DeliveryManager::update(Model* model, sf::Time deltaTime)
{
	deliveryTimer += deltaTime;
	spawnTimer += deltaTime;

	for (unsigned int i = 0; i < deliveries.size(); i++)
	{
		if (deliveries[i]->checkExpired(deliveryTimer))
		{
			std::cout << "Delivery Expired!" << std::endl;
			availableTiles.push_back(deliveries[i]->getPickupPoint());
			availableTiles.push_back(deliveries[i]->getDropoffPoint());
			deliveries.erase(deliveries.begin() + i);
		}
		else if (deliveries[i]->isDroppedOff()) 
		{
			availableTiles.push_back(deliveries[i]->getPickupPoint());
			availableTiles.push_back(deliveries[i]->getDropoffPoint());
			deliveries.erase(deliveries.begin() + i);
		}
	}

	if (spawnTimer.asSeconds() > spawnInterval && availableTiles.size() >= 2)
	{
		//std::cout << "New Delivery" << std::endl;
		newDelivery(model);
		spawnTimer = sf::Time::Zero;
	}
}

void DeliveryManager::render(View* view)
{
	for (unsigned int i = 0; i < deliveries.size(); i++)
	{
		sf::Vector2u pickupPoint = deliveries[i]->getPickupPoint();
		pickupMan.setPosition(sf::Vector2f(pickupPoint.x * 130 + 45, pickupPoint.y * 130 + 45));
		view->window.draw(pickupMan);

		sf::Vector2u dropOffPoint = deliveries[i]->getDropoffPoint();
		dropOffMan.setPosition(sf::Vector2f(dropOffPoint.x * 130 + 45, dropOffPoint.y * 130 + 45));
		view->window.draw(dropOffMan);
	}
}

void DeliveryManager::newDelivery(Model* model)
{
	sf::Vector2u pickupTile; int pickupIndex;
	sf::Vector2u dropoffTile; int dropoffIndex;
	do {
		pickupIndex = getRandomTile(availableTiles, pickupTile);
		dropoffIndex = getRandomTile(availableTiles, dropoffTile);
	} while (tileDistance(pickupTile, dropoffTile) < minDistance);
	std::cout << availableTiles.size() << std::endl;
	std::cout << pickupIndex << " " << dropoffIndex << std::endl;
	std::cout << "(" << pickupTile.x << " " << pickupTile.y << ")" << " (" << dropoffTile.x << " " << dropoffTile.y << ")" << std::endl;
	availableTiles.erase(availableTiles.begin() + pickupIndex);
	dropoffIndex = (pickupIndex < dropoffIndex) ? dropoffIndex - 1 : dropoffIndex;
	availableTiles.erase(availableTiles.begin() + dropoffIndex);
	//availableTiles.erase(availableTiles.begin() + availableTiles.size() - 1);

	//std::cout << "(" << pickupTile.x << " " << pickupTile.y << ")" << " (" << dropoffTile.x << " " << dropoffTile.y << ")" << std::endl;

	Delivery* newDelivery = new Delivery("testDel", "Assets/car_green_1.png", pickupTile, dropoffTile, deliveryTimer + sf::Time(sf::seconds(30)));
	deliveries.push_back(newDelivery);
	model->inventory->addToInventory(newDelivery);
}

int DeliveryManager::getRandomTile(std::vector<sf::Vector2u> tiles, sf::Vector2u& outputTile)
{
	int x = rand() % tiles.size();
	outputTile = tiles[x];
	return x;
}

float DeliveryManager::tileDistance(sf::Vector2u tile_1, sf::Vector2u tile_2)
{
	return sqrt(pow(tile_1.x - tile_2.x, 2) + pow(tile_1.y - tile_2.y, 2));
}

void DeliveryManager::pickupDelivery(Delivery* delivery)
{
	delivery->pickUp();
	std::cout << "PICKED UP" << std::endl;
}

void DeliveryManager::dropoffDelivery(Delivery* delivery)
{
	std::cout << "DROPPED OFF" << std::endl;
	delivery->dropOff();
}

Delivery* DeliveryManager::getDeliveryAt(sf::Vector2u point)
{
	for (unsigned int i = 0; i < deliveries.size(); i++)
	{
		if (point == deliveries[i]->getPickupPoint() ||
			point == deliveries[i]->getDropoffPoint())
			return deliveries[i];
	}
	return NULL;
}
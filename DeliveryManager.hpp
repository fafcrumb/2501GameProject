#pragma once

#include <SFML/Graphics.hpp>

#include "Delivery.hpp"
#include "Model.hpp"
#include "View.hpp"

class DeliveryManager: public Updateable, public Renderable
{
public:
	DeliveryManager(std::vector<sf::Vector2u>);
	~DeliveryManager();
	void update(Model*, sf::Time deltaTime);
	void render(View*);
	void newDelivery(Model*);
	void pickupDelivery(Delivery*);
	void dropoffDelivery(Delivery*);
	Delivery* getDeliveryAt(sf::Vector2u);

private:
	std::vector<sf::Vector2u> availableTiles;
	sf::Time deliveryTimer;
	sf::Time spawnTimer;
	int spawnInterval;
	std::vector<Delivery*> deliveries;
	std::vector<sf::Vector2u> occupiedSpaces;
	int getRandomTile(std::vector<sf::Vector2u>, sf::Vector2u&);
	float tileDistance(sf::Vector2u, sf::Vector2u);
	float minDistance;

	sf::RectangleShape item;

	sf::Image pickupManImage;
	sf::Texture pickupManTexture;
	sf::Sprite pickupManSprite;

	sf::Image dropOffManImage;
	sf::Texture dropOffManTexture;
	sf::Sprite dropOffManSprite;
};

#pragma once

#include <fstream>
#include <SFML/Graphics.hpp>

#include "Updateable.hpp"
#include "Player.hpp"
#include "DeliveryTruck.hpp"
#include "Camera.hpp"
#include "Speedometer.hpp"
#include "Inventory.hpp"
#include "TileManager.hpp"
#include "DeliveryManager.hpp"

class Player;
class DeliveryTruck;
class DeliveryManager;
class Speedometer;
class Inventory;
class Camera;

class Model
{
public:
	Model();
	~Model();

	void update(sf::Time);
	bool collidingWithBuilding(sf::FloatRect rect);

	int mapWidth, mapHeight;
	int **mapTiles;
	int *tiles;

	Player* player;
	Camera* camera;
	DeliveryTruck* truck;
	DeliveryManager* deliveryManager;
	Speedometer* speedometer;
	Inventory* inventory;

	TileManager* tileManager;

	std::vector<Updateable*> updateables;
};
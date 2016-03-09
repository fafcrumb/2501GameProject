#pragma once

#include <fstream>
#include <SFML/Graphics.hpp>

#include "Updateable.hpp"
#include "Player.hpp"
#include "DeliveryTruck.hpp"
#include "Camera.hpp"
#include "Tile.hpp"

class Player;
class DeliveryTruck;
class Camera;

class Model
{
public:
	Model();
	~Model();

	void update(sf::Time);

	int mapWidth, mapHeight;
	int **mapTiles;

	Tile ***tileProperties;
	Camera* camera;
	Player* player;
	DeliveryTruck* truck;

	std::vector<Updateable*> updateables;

	bool inTruck;
};

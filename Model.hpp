#pragma once

#include <fstream>
#include <SFML/Graphics.hpp>

#include "Updateable.hpp"
#include "Player.hpp"
#include "DeliveryTruck.hpp"
#include "Camera.hpp"
#include "Speedometer.hpp"
#include "TimeDisplay.hpp"

class Player;
class DeliveryTruck;
class Speedometer;
class Camera;
class TimeDisplay;

class Model
{
public:
	Model();
	~Model();

	void update(sf::Time);

	int mapWidth, mapHeight;
	int **mapTiles;

	Camera* camera;
	Player* player;
	DeliveryTruck* truck;
	Speedometer* speedometer;
	TimeDisplay* timeDisplay;

	std::vector<Updateable*> updateables;

	bool inTruck;
};

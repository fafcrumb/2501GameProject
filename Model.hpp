#pragma once

#include <fstream>
//#include <math.h>
#include <SFML/Graphics.hpp>

class Model
{
public:
	Model();
	~Model();

	void update(sf::Time);

	//Map
	int mapWidth, mapHeight;
	int **mapTiles;

	//Camera
	int cameraWidth, cameraHeight;
	int cameraCol, cameraRow;
	float cameraX, cameraY;
	int *cameraTiles;

	//Player
	int playerCol, playerRow;
	float playerX, playerY;
	int playerSpeed;

	//Car
	int carCol, carRow;

	sf::Vector2f carLocation;
	float carHeading;
	float carSpeed;
	float steerAngle;
	float wheelBase; // the distance between the two axles
};

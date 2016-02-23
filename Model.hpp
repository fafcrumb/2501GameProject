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

	int mapWidth, mapHeight;
	int **mapTiles;

	int cameraWidth, cameraHeight;
	int cameraCol, cameraRow;
	float cameraX, cameraY;
	int *cameraTiles;

	int playerCol, playerRow;
	float playerX, playerY;
	int playerSpeed;

	int carCol, carRow;

	sf::Vector2f carLocation;
	float carHeading;
	float carSpeed;
	float steerAngle;
	float wheelBase; // the distance between the two axles	
};
#include "Model.hpp"
#include <iostream>
Model::Model()
{
	//Map

	std::ifstream fileHndl;

	fileHndl.open("Assets/mapdata.txt");

	fileHndl >> mapWidth;
	fileHndl >> mapHeight;

	mapTiles = new int *[mapHeight];
	for (int i = 0; i < mapHeight; i++)
		mapTiles[i] = new int[mapWidth];

	for (int i = 0; i < mapHeight; i++)
		for (int j = 0; j < mapWidth; j++)
			fileHndl >> mapTiles[i][j];

	//Camera

	cameraWidth = cameraHeight = 8;
	cameraCol = cameraRow = 0;
	cameraX = cameraY = 0.f;

	cameraTiles = new int[cameraWidth * cameraHeight];
	int k = 0;
	for (int i = cameraRow; i < cameraRow + cameraHeight; i++)
		for (int j = cameraCol; j < cameraCol + cameraWidth; j++)
		{
			cameraTiles[k] = mapTiles[i][j];
			k++;
		}

	//Player

	playerCol = playerRow = 3;
	playerX = playerY = 32 * (float)playerRow + 16;
	playerSpeed = 8;

	//Car

	carCol, carRow = 5;

	carLocation = sf::Vector2f(144, 144);

	carHeading = 0;
	carSpeed = 0;
	steerAngle = 0;
	wheelBase = 32; // the distance between the two axles	
}

Model::~Model()
{}

void Model::update(sf::Time deltaTime)
{
	//Player

	if (playerX + 16 >= (mapWidth-1) * 32)
		playerX = (float)(mapWidth-1) * 32 - 16;
	if (playerX - 16 <= 0)
		playerX = 16;
	if (playerY + 16 >= (mapHeight-1) * 32)
		playerY = (float)(mapHeight-1) * 32 - 16;
	if (playerY - 16 <= 0)
		playerY = 16;

	playerCol = (int)playerX / 32;
	playerRow = (int)playerY / 32;

	//Car

	//max speed
	if (abs(carSpeed) > 100)
	{
		if (carSpeed < 0)
			carSpeed = -100;
		else
			carSpeed = 100;
	}

	//friction
	if (carSpeed > 0)
	{
		carSpeed -= 5;
		if (carSpeed < 0)
			carSpeed = 0;
	}
	else
	{
		carSpeed += 5;
		if (carSpeed > 0)
			carSpeed = 0;
	}
		


	sf::Vector2f frontWheel = carLocation + wheelBase / 2 * sf::Vector2f(cos(carHeading), sin(carHeading));
	sf::Vector2f backWheel = carLocation - wheelBase / 2 * sf::Vector2f(cos(carHeading), sin(carHeading));

	backWheel += carSpeed * deltaTime.asSeconds() * sf::Vector2f(cos(carHeading), sin(carHeading));
	frontWheel += carSpeed * deltaTime.asSeconds() * sf::Vector2f(cos(carHeading + steerAngle), sin(carHeading + steerAngle));

	carLocation = (frontWheel + backWheel) / 2.f;
	carHeading = atan2(frontWheel.y - backWheel.y, frontWheel.x - backWheel.x);

	carCol = (int)carLocation.x / 32;
	carRow = (int)carLocation.y / 32;

	//Camera

	cameraX = playerX - 112.f;
	cameraY = playerY - 112.f;

	if (cameraX + cameraWidth * 32 >= mapWidth * 32)
		cameraX = (float)mapWidth * 32 - cameraWidth * 32;
	if (cameraX <= 0)
		cameraX = 0;
	if (cameraY + cameraHeight * 32 >= mapHeight * 32)
		cameraY = (float)mapHeight * 32 - cameraHeight * 32;
	if (cameraY <= 0)
		cameraY = 0;

	cameraCol = (int)cameraX / 32;
	cameraRow = (int)cameraY / 32;

	int k = 0;
	for (int i = cameraRow; i < cameraRow + cameraHeight; i++)
		for (int j = cameraCol; j < cameraCol + cameraWidth; j++)
		{
			cameraTiles[k] = mapTiles[i][j];
			k++;
		}
}
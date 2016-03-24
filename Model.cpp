#include "Model.hpp"
#include <iostream>
Model::Model()
{
	std::ifstream fileHndl;

	tileManager = new TileManager();

	fileHndl.open("Assets/mapdata.txt");

	fileHndl >> mapWidth;
	fileHndl >> mapHeight;

	//load map tiles from file
	mapTiles = new int *[mapHeight];
	for (int i = 0; i < mapHeight; i++)
		mapTiles[i] = new int[mapWidth];

	for (int i = 0; i < mapHeight; i++)
		for (int j = 0; j < mapWidth; j++)
		{
			fileHndl >> mapTiles[i][j];

			if (mapTiles[i][j] == 1)
				tileManager->addStreetTile(sf::Vector2u(j, i));
			if (mapTiles[i][j] == 2)
				tileManager->addSidewalkTile(sf::Vector2u(j, i));
			if (mapTiles[i][j] == 3)
				tileManager->addBuildingTile(sf::Vector2u(j, i));
		}

	tiles = new int[mapWidth * mapHeight];
	for (int i = 0; i < mapHeight; i++)
		for (int j = 0; j < mapWidth; j++)
			tiles[j + i * mapWidth] = mapTiles[i][j];
		
	truck = new DeliveryTruck();
	camera = new Camera(mapTiles, mapWidth, mapHeight, truck->getCol(), truck->getRow());
	player = new Player();
	deliveryManager = new DeliveryManager(tileManager->getSidewalkTiles());
	speedometer = new Speedometer();
	inventory = new Inventory();

	updateables.push_back(truck);
	updateables.push_back(camera);
	updateables.push_back(player);
	updateables.push_back(speedometer);
	updateables.push_back(deliveryManager);
	updateables.push_back(inventory);
}

Model::~Model()
{}

void Model::update(sf::Time deltaTime)
{
	for (Updateable* object : updateables)
		object->update(this, deltaTime);
}

bool Model::collidingWithBuilding(sf::FloatRect rect)
{
	for (int i = 0; i < tileManager->getBuildingTiles().size(); i++)
	{
		sf::Vector2u buildingTile = tileManager->getBuildingTiles(i);
		sf::FloatRect buildingRect((float)buildingTile.x * 130.f, (float)buildingTile.y * 130.f, 130.f, 130.f);
		if (rect.intersects(buildingRect))
			return true;
	}
	return false;
}
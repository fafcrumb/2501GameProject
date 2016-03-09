#include "Model.hpp"

Model::Model()
{
	std::ifstream fileHndl;

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
			tileProperties[i][j] = new Tile(mapTiles[i][j]);
		}

	camera = new Camera(tileProperties);
	player = new Player();
	truck = new DeliveryTruck();

	updateables.push_back(camera);
	updateables.push_back(player);
	updateables.push_back(truck);

	bool inTruck = false;
}

Model::~Model()
{}

void Model::update(sf::Time deltaTime)
{
	for (Updateable* object : updateables)
		object->update(this, deltaTime);
}

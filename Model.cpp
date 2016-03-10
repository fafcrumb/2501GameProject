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
			fileHndl >> mapTiles[i][j];

	camera = new Camera(mapTiles);
	player = new Player();
	truck = new DeliveryTruck();
	speedometer = new Speedometer();
	timeDisplay= new TimeDisplay();

	updateables.push_back(camera);
	updateables.push_back(player);
	updateables.push_back(truck);
	updateables.push_back(speedometer);
	updateables.push_back(timeDisplay);

	bool inTruck = false;
}

Model::~Model()
{}

void Model::update(sf::Time deltaTime)
{
	for (Updateable* object : updateables)
		object->update(this, deltaTime);
}

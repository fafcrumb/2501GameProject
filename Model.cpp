#include "Model.hpp"

Model::Model()
{
	std::ifstream fileHndl;

	fileHndl.open("Assets/mapdata.txt");

	fileHndl >> mapWidth;
	fileHndl >> mapHeight;
	int width = mapWidth;
	tileProperties = new Tile **[mapHeight];
	roadBlocks = 50;
	//load map tiles from file
	mapTiles = new int *[mapHeight];
	for (int i = 0; i < mapHeight; i++)
		mapTiles[i] = new int[mapWidth];
	for (int i = 0; i < mapHeight; i++)
	{
		tileProperties[i] = new Tile*[mapWidth];
		for (int j = 0; j < mapWidth; j++)
		{
			int temp;
			fileHndl >> mapTiles[i][j];
			tileProperties[i][j] = new Tile(mapTiles[i][j]);
		}
	}

	camera = new Camera(tileProperties);
	player = new Player();
	truck = new DeliveryTruck();
	int centerX = camera->getRow() + camera->getWidth() / 2;
	int centerY = -camera->getCol() + camera->getHeight() / 2;
	while (roadBlocks != 0) {
		int x = rand() % mapWidth;
		int y = rand() % mapHeight;
		if (tileProperties[y][x]->returnMapCode() == 1 && abs(x - centerX) > 3 && abs(y - centerY) > 3) {
			tileProperties[y][x]->setBlockade();
			roadBlocks -= 1;
		}
	}

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

#include "world.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
world::world() {
	worldWidth = 3000;
	worldHeight = 3000;
	numWorldTilesX = 100;
	numWorldTilesY = 100;
	tileWidth = worldWidth / numWorldTilesX;
	tileHeight = worldHeight / numWorldTilesY;
	screenWidth = 600;
	screenHeight = 600;
	screenTilesX = screenWidth / tileWidth;
	screenTilesX = screenHeight / tileHeight;
	//getSprites();
	worldSetup();
}
world::~world() {}

void world::update() {

}

void world::render() {

}

void world::worldSetup() {
	string lineNum;
	ifstream mapFile ("map.txt");
	if (mapFile.is_open()) {
		for (int y = 0; y < numWorldTilesY; y++) {
			for (int x = 0; x < numWorldTilesX; x++) {
				getline(mapFile, lineNum);
				tiles[x][y] = tile(x*tileWidth, y * tileHeight, stoi(lineNum));
			}
		}
		mapFile.close();
	}
}
void world::getSprites() {
	//retrival of sprite texture names from file which are then used to load the sprites into the sprite vector
}

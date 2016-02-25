#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "tile.h"

class world
{
public:
	world();
	~world();
	void update();
	void render();
	void getSprites();
	int  getTileX();
	int  getTileY();
	void worldSetup();
private:
	std::vector<std::vector<tile>> tiles;
	std::vector<sf::Sprite> sprites;
	int numWorldTilesX;
	int numWorldTilesY;
	int worldWidth;
	int worldHeight;
	int tileWidth;
	int tileHeight;
	int screenWidth;
	int screenHeight;
	int screenTilesX;
	int screenTilesY;
};

#include "TileManager.hpp"

TileManager::TileManager()
{}

TileManager::~TileManager()
{}

void TileManager::addBuildingTile(sf::Vector2u tileLoc)
{
	buildingTiles.push_back(tileLoc);
}

void TileManager::addStreetTile(sf::Vector2u tileLoc)
{
	streetTiles.push_back(tileLoc);
}

void TileManager::addSidewalkTile(sf::Vector2u tileLoc)
{
	sidewalkTiles.push_back(tileLoc);
}

std::vector<sf::Vector2u> TileManager::getBuildingTiles()
{
	return buildingTiles;
}

sf::Vector2u TileManager::getBuildingTiles(int i)
{
	return buildingTiles[i];
}

std::vector<sf::Vector2u> TileManager::getSidewalkTiles()
{
	return sidewalkTiles;
}
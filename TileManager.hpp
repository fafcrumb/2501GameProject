#pragma once

#include <SFML\Graphics.hpp>

class TileManager
{
public:
	TileManager();
	~TileManager();

	void addBuildingTile(sf::Vector2u);
	void addStreetTile(sf::Vector2u);
	void addSidewalkTile(sf::Vector2u);

	std::vector<sf::Vector2u> getBuildingTiles();
private:
	std::vector<sf::Vector2u> buildingTiles;
	std::vector<sf::Vector2u> streetTiles;
	std::vector<sf::Vector2u> sidewalkTiles;
};

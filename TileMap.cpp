#include "TileMap.hpp"

//Separated loading texture image from loading
//tile values
bool TileMap::loadTexture(const std::string& tileset)
{
	// load the tileset texture
	if (!m_tileset.loadFromFile(tileset))
		return false;
	else
		return true;
}

bool TileMap::loadTiles(sf::Vector2u tileSize, Tile** tiles, unsigned int width, unsigned int height)
{
	// resize the vertex array to fit the level size
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);

	// populate the vertex array, with one quad per tile
	for (unsigned int i = 0; i < width; ++i)
		for (unsigned int j = 0; j < height; ++j)
		{
			// get the current tile number
			int tileNumber = tiles[i + j * width]->returnMapCode();

			// find its position in the tileset texture
			int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
			int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

			// get a pointer to the current tile's quad
			sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

			// define its 4 corners
			quad[0].position = sf::Vector2f(i * (float)tileSize.x, j * (float)tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * (float)tileSize.x, j * (float)tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * (float)tileSize.x, (j + 1) * (float)tileSize.y);
			quad[3].position = sf::Vector2f(i * (float)tileSize.x, (j + 1) * (float)tileSize.y);

			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(tu * (float)tileSize.x, tv * (float)tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * (float)tileSize.x, tv * (float)tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * (float)tileSize.x, (tv + 1) * (float)tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * (float)tileSize.x, (tv + 1) * (float)tileSize.y);
		}

	return true;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// apply the transform
	states.transform *= getTransform();

	// apply the tileset texture
	states.texture = &m_tileset;

	// draw the vertex array
	target.draw(m_vertices, states);
}

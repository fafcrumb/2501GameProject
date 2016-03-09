#pragma once
// loadTiles second parameter changed to support tile** object
// Include Tile.h
#include <SFML/Graphics.hpp>
#include "Tile.h"
/*
 TileMap vertex array class
 from SFML tutorial
 Source: http://www.sfml-dev.org/tutorials/2.0/graphics-vertex-array.php */

class TileMap : public sf::Drawable, public sf::Transformable
{
public:

	bool loadTexture(const std::string&);
	bool loadTiles(sf::Vector2u, Tile**, unsigned int, unsigned int);

private:

	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
};

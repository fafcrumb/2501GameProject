#pragma once

#include <SFML/Graphics.hpp>

#include "Model.hpp"
#include "View.hpp"


class Speedometer : public Updateable, public Renderable
{
public:
	Speedometer();
	~Speedometer();
	void update(Model*, sf::Time deltaTime);
	void render(View*);
private:
	float angle;
	float x, y;

	sf::Image baseImage;
	sf::Texture baseTexture;
	sf::Sprite baseSprite;

	sf::Image needleImage;
	sf::Texture needleTexture;
	sf::Sprite needleSprite;
};

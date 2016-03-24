#include "Speedometer.hpp"
#include <iostream>
Speedometer::Speedometer()
{
	this->angle = 180;

	baseImage.loadFromFile("Assets/speedometerBase.png");
	needleImage.loadFromFile("Assets/speedometerNeedle.png");

	baseImage.createMaskFromColor(sf::Color::White);
	needleImage.createMaskFromColor(sf::Color::White);

	baseTexture.loadFromImage(baseImage);
	needleTexture.loadFromImage(needleImage);

	baseTexture.setSmooth(true);
	needleTexture.setSmooth(true);

	baseSprite.setTexture(baseTexture);
	needleSprite.setTexture(needleTexture);

	baseSprite.setColor(sf::Color(255, 255, 255, 200));
	needleSprite.setColor(sf::Color(255, 255, 255, 200));

	//baseSprite.setScale(sf::Vector2f(1.f, 1.f));
	//needleSprite.setScale(sf::Vector2f(1.f, 1.f));

	needleSprite.setOrigin(sf::Vector2f(10, 20));
}

Speedometer::~Speedometer()
{}

void Speedometer::update(Model* model, sf::Time deltaTime)
{
	if (model->player->inVehicle)
	{
		x = 1140;
		y = 630;
		angle = 260.0f / 600 * abs(model->truck->getSpeed()) + 180;
	}
}

void Speedometer::render(View* view)
{
	if (view->model->player->inVehicle)
	{
		baseSprite.setPosition(sf::Vector2f(x, y));
		needleSprite.setPosition(sf::Vector2f(x + 63, y + 63));
		needleSprite.setRotation(angle);
		view->window.draw(baseSprite);
		view->window.draw(needleSprite);
	}
}
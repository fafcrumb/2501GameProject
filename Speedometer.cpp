#include "Speedometer.hpp"

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
	
	baseSprite.setScale(sf::Vector2f(0.25f, 0.25f));
	needleSprite.setScale(sf::Vector2f(0.25f, 0.25f));

	needleSprite.setOrigin(sf::Vector2f(10, 20));
}

Speedometer::~Speedometer() 
{}

void Speedometer::update(Model* model, sf::Time deltaTime)
{
	if (model->inTruck)
	{
		x = model->camera->getX() + 193;
		y = model->camera->getY() + 193;
		angle = 260.0f / 400 * abs(model->truck->getSpeed()) + 180;
	}
}

void Speedometer::render(View* view)
{
	if (view->model->inTruck) 
	{
		baseSprite.setPosition(sf::Vector2f(x - view->model->camera->getX() , y - view->model->camera->getY()));
		needleSprite.setPosition(sf::Vector2f(x - view->model->camera->getX() + 16, y - view->model->camera->getY() + 16));
		needleSprite.setRotation(angle);
		view->window.draw(baseSprite);
		view->window.draw(needleSprite);
	}
}

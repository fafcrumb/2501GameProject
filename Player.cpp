#include "Player.hpp"

Player::Player()
{
	col = row = 3;
	x = y = 32 * (float)row + 16;
	speed = 8;

	rect.setSize(sf::Vector2f(32, 32));
	rect.setOrigin(sf::Vector2f(16, 16));
	rect.setFillColor(sf::Color::Red);
	rect.setPosition(sf::Vector2f(y, y));
}

Player::~Player()
{}

void Player::update(Model* model, sf::Time deltaTime)
{
	//Player bounds
	if (x + 16 >= (model->mapWidth - 1) * 32)
		x = (float)(model->mapWidth - 1) * 32 - 16;
	if (x - 16 <= 0)
		x = 16;
	if (y + 16 >= (model->mapHeight - 1) * 32)
		y = (float)(model->mapHeight - 1) * 32 - 16;
	if (y - 16 <= 0)
		y = 16;

	col = (int)x / 32;
	row = (int)y / 32;
}

void Player::render(View* view)
{
	rect.setPosition(sf::Vector2f(x - view->model->camera->getX(), y - view->model->camera->getY()));
	view->window.draw(rect);
}

void Player::moveUp() { y -= speed; }

void Player::moveDown() { y += speed; }

void Player::moveLeft() { x -= speed; }

void Player::moveRight() { x += speed; }
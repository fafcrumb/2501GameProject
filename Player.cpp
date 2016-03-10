#include "Player.hpp"

Player::Player()
{
	col = row = 3;
	x = y = 32 * (float)row + 16;
	speed = 8;
	xMod = 0;
	yMod = 0;
	rect.setSize(sf::Vector2f(32, 32));
	rect.setOrigin(sf::Vector2f(16, 16));
	rect.setFillColor(sf::Color::Red);
	rect.setPosition(sf::Vector2f(y, y));
}

Player::~Player()
{}

void Player::update(Model* model, sf::Time deltaTime)
{
	float tempCol = (x + 16 * xMod) / 32;
	float tempRow = (y + 16 * yMod) / 32;
	//Player bounds
	/*if (x + 16 >= (model->mapWidth - 1) * 32)
		x = (float)(model->mapWidth - 1) * 32 - 16;
	if (x - 16 <= 0)
		x = 16;
	if (y + 16 >= (model->mapHeight - 1) * 32)
		y = (float)(model->mapHeight - 1) * 32 - 16;
	if (y - 16 <= 0)
		y = 16;*/
	if (tempCol <= (model->mapWidth - 1.01) && tempCol >= 0.01 && model->tileProperties[row][(int)tempCol]->returnBlockable() == 0)
		x += 4 * xMod;
	if ( tempRow <= (model->mapHeight - 1.01)  && tempRow >= 0.01 && model->tileProperties[(int)tempRow][col]->returnBlockable() == 0)
		y += 4 * yMod;

	col = (int)x / 32;
	row = (int)y / 32;
	xMod = 0;
	yMod = 0;
}

void Player::render(View* view)
{
	rect.setPosition(sf::Vector2f(x - view->model->camera->getX(), y - view->model->camera->getY()));
	view->window.draw(rect);
}


void Player::moveUp() { yMod = -1; }
void Player::moveDown() { yMod = 1; }
void Player::moveLeft() { xMod = -1; }
void Player::moveRight() { xMod = 1; }


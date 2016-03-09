#include "Player.hpp"
// Overhauled movement to incorporate a check before move collision
// X and Y displacement removed from move functions and placed in update with the move functions instead changing a modifier which causes the displacement once update occurs
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
	// New ///////
	int tempCol = (int)(x + 16 * xMod) / 32;
	int tempRow = (int)(y + 16 * yMod) / 32;
	//Player bounds
	/*if (x + 16 >= (model->mapWidth - 1) * 32)
		x = (float)(model->mapWidth - 1) * 32 - 16;
	if (x - 16 <= 0)
		x = 16;
	if (y + 16 >= (model->mapHeight - 1) * 32)
		y = (float)(model->mapHeight - 1) * 32 - 16;
	if (y - 16 <= 0)
		y = 16;*/
	if (!(x + 16 >= (model->mapWidth - 1) * 32) && !(x - 16 <= 0) && model->tileProperties[row][tempCol]->returnBlockable() == 0)
		x += 16 * xMod;
	if ( !(y + 16 >= (model->mapHeight - 1) * 32) && !(y - 16 <= 0) && model->tileProperties[tempRow][col]->returnBlockable() == 0)
		y += 16 * yMod;
	///////////////////////////////
	col = (int)x / 32;
	row = (int)y / 32;
	xMod = 0; // New
	yMod = 0; // New
}

void Player::render(View* view)
{
	rect.setPosition(sf::Vector2f(x - view->model->camera->getX(), y - view->model->camera->getY()));
	view->window.draw(rect);
}

/// Functions changed
void Player::moveUp() { yMod = -1; }
void Player::moveDown() { yMod = 1; }
void Player::moveLeft() { xMod = -1; }
void Player::moveRight() { xMod = 1; }

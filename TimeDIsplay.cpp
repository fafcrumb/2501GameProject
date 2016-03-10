#include "TimeDisplay.hpp"

TimeDisplay::TimeDisplay()
{
	font.loadFromFile("Assets/arial.ttf");
	mils = 3600000 * 8;
}
TimeDisplay::~TimeDisplay(){}

void TimeDisplay::update(Model* model, sf::Time deltaTime) 
{
	mils += deltaTime.asMilliseconds();
	hour = mils / 3600000;
	minute = (mils % 3600000) / 60000;
	second = ((mils % 3600000) % 60000) / 1000; 
}

void TimeDisplay::render(View* view)
{
	std::string string = "" + hour + ':' + minute + '.' + second;
	sf::Text display("Time goes here?", font);
	display.setCharacterSize(10);
	display.setStyle(sf::Text::Regular);
	display.setColor(sf::Color::Black);
	display.setPosition(sf::Vector2f(view->model->camera->getX() - view->model->camera->getX() + 5, view->model->camera->getY() - view->model->camera->getY()));
	view->window.draw(display);
}

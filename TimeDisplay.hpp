#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "Model.hpp"
#include "View.hpp"

class TimeDisplay : public Updateable, public Renderable
{
public:
	TimeDisplay();
	~TimeDisplay();
	void update(Model*, sf::Time deltaTime);
	void render(View*);
private: 
	int mils, hour, minute, second;
	sf::Font font;
	sf::Text display;
};

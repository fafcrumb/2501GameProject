#pragma once

#include "Model.hpp"

class Model;

class Updateable
{
public:
	virtual void update(Model*, sf::Time) = 0;
};
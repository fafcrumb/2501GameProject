#pragma once

#include "View.hpp"

class View;

class Renderable
{
public:
	virtual void render(View*) = 0;
};
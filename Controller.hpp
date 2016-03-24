#pragma once

#include "Model.hpp"
#include "View.hpp"

class Controller
{
public:
	Model* model;
	View* view;

	Controller(Model* m, View* v);
	~Controller();

	void inputs();
};

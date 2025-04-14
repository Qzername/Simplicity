#pragma once

#include <list>
#include "drawable.h"

class Scene {
	Color backgroundColor;
public:
	std::vector<Drawable*> objects;

	Scene();

	Color getBackgroundColor();
	void setBackgroundColor(Color backgroundColor);

	void Instantiate(Drawable* shaderProgram);
	void Destroy(Drawable* shaderProgram);
};
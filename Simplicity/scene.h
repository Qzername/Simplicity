#pragma once

#include <list>
#include "renderer.h"

class Scene {
	std::vector<GraphicsObject*> objects;
public:
	void Render(Renderer* renderer);

	void Instantiate(GraphicsObject* shaderProgram);
	void Destroy(GraphicsObject* shaderProgram);
};
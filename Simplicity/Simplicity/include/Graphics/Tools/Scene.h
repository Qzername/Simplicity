#pragma once

#include <Graphics/Renderer.h>

class Scene {
	std::vector<GraphicsObject*> objects;
public:
	void Render(Renderer* renderer);

	void Instantiate(GraphicsObject* shaderProgram);
	void Destroy(GraphicsObject* shaderProgram);
};
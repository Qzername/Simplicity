#pragma once

#include <Graphics/Objects/GraphicsObject.h>
#include <Graphics/Objects/Color.h>

class Renderer {
	unsigned int shaderProgram;

public:
	Renderer();
	Renderer(unsigned int shaderProgram);

	Color backgroundColor;

	void Render(GraphicsObject graphicsObject);
	void Clear();
};
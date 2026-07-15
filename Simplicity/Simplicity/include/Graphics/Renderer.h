#pragma once

#include "coreDefinitions.h"

#include <Graphics/Objects/GraphicsObject.h>
#include <Graphics/Objects/Color.h>

class CPP_LIB_EXP Renderer {
	unsigned int shaderProgram;

public:
	Renderer();
	Renderer(unsigned int shaderProgram);

	Color backgroundColor;

	void Render(GraphicsObject graphicsObject);
	void Clear();
};
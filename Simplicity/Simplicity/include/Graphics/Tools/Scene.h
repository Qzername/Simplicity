#pragma once

#include "coreDefinitions.h"

#include <Graphics/Renderer.h>

class CPP_LIB_EXP Scene {
	std::vector<GraphicsObject*> objects;
public:
	void Render(Renderer* renderer);

	void Instantiate(GraphicsObject* shaderProgram);
	void Destroy(GraphicsObject* shaderProgram);
};
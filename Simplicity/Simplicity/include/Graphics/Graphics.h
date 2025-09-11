#pragma once

#include "Camera.h"
#include "Renderer.h"

struct Graphics {
	unsigned int shaderProgram;

public:
	void Initialize();

	Camera camera;
	Renderer renderer;
};
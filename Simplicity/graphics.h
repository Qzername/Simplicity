#pragma once

#include "camera.h"
#include "renderer.h"

struct Graphics {
	unsigned int shaderProgram;

public:
	void Initialize();

	Camera camera;
	Renderer renderer;
};
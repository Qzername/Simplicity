#include "graphics.h"
#include "shaderCompiling.h"

#include <iostream>

void Graphics::Initialize()
{
	shaderProgram = compileShaders(loadDefaultShaders());

	renderer = Renderer(shaderProgram);
	camera.Config(shaderProgram);

	glUseProgram(shaderProgram);
}
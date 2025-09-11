#include <Graphics/Renderer.h>
#include <Graphics/Objects/GraphicsObject.h>

#include <glad/glad.h>

Renderer::Renderer() {
	shaderProgram = 0;
}

Renderer::Renderer(unsigned int shaderProgram)
{
	this->shaderProgram = shaderProgram;
}

void Renderer::Render(GraphicsObject graphicsObject) {
	graphicsObject.render(shaderProgram);
}

void Renderer::Clear()
{
	glClearColor(backgroundColor.r / 255, backgroundColor.g / 255, backgroundColor.b / 255, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
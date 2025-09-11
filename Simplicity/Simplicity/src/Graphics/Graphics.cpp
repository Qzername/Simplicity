#include <Graphics/Graphics.h>
#include <ShaderCompiling.h>

#include <glad/glad.h>

void Graphics::Initialize()
{
	shaderProgram = compileShaders(loadDefaultShaders());

	renderer = Renderer(shaderProgram);
	camera.Config(shaderProgram);

	glUseProgram(shaderProgram);
}
#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <Input/Input.h>
#include <Graphics/Graphics.h>
#include <Graphics/Objects/Texture2D.h>

typedef void(*OnFrameCallback)();

class Window
{
	GLFWwindow* window;
	unsigned int shaderProgram;
	Texture2D defaultTexture;

	float lastFrame = 0.0f;
	OnFrameCallback onFrame = nullptr;

	void frameCalculations();
public:
	Graphics graphics;
	Input input;

	float deltaTime = 0.0f;

	Window(const char* windowName);
	~Window();

	void show();
	void close();

	void setOnFrameCallback(OnFrameCallback cb);
};		
#pragma once
#include "initializationTools.h"
#include "shaderCompiling.h"
#include "input.h"
#include "graphics.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <list>
#include <functional>

typedef void(*OnFrameCallback)();

class Window
{
	GLFWwindow* window;
	unsigned int shaderProgram;
	Texture2D defaultTexture;

	float lastFrame = 0.0f;
	OnFrameCallback onFrame = nullptr;

	void frameCalculations();
	void render();

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
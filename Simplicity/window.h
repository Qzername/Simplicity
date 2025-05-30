#pragma once
#include "initializationTools.h"
#include "shaderCompiling.h"
#include "drawable.h"
#include "camera.h"
#include "scene.h"
#include "input.h"

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
	Input input;

	Scene scene;
	Camera camera;
	float deltaTime = 0.0f;

	Window(const char* windowName);
	~Window();

	void show();

	void setOnFrameCallback(OnFrameCallback cb);

	void setMouseInputMode(int value);
	void close();
};		
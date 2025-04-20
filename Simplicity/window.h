#pragma once
#include "initializationTools.h"
#include "shaderCompiling.h"
#include "drawable.h"
#include "camera.h"
#include "scene.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <list>
#include <functional>

typedef void(*OnFrameCallback)();

class Window
{
	GLFWwindow* window;

	unsigned int shaderProgram;

	float lastFrame = 0.0f;

	void frameCalculations();
	void render();

	OnFrameCallback onFrame = nullptr; 

public:
	Scene scene;
	Camera camera;
	float deltaTime = 0.0f;

	Window(const char* windowName);
	~Window();

	void show();

	void setOnFrameCallback(OnFrameCallback cb);

	int getKey(int key);
	vector3 getCursorPos();

	void setMouseInputMode(int value);
	void close();
};		
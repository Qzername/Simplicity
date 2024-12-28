#pragma once
#include "initializationTools.h"
#include "shaderCompiling.h"
#include "drawable.h"
#include "camera.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <list>
#include <functional>

class Window
{
	GLFWwindow* window;
	unsigned int shaderProgram;

	float lastFrame = 0.0f;

public:
	Camera camera;
	float deltaTime = 0.0f;

	Window(const char* windowName);
	~Window();

	bool shouldClose();
	void frameCalculations();
	void clear(Color color);
	void draw(Drawable* drawable);
	void render();

	int getKey(int key);
	vector3 getCursorPos();

	void setMouseInputMode(int value);
	void close();
};
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
	std::list<Drawable*> objectList;

	GLFWwindow* window;
	unsigned int shaderProgram;

	//callbacks
	std::function<void(GLFWwindow*)> keyboardCallback;

public:
	Camera camera;

	Window(const char* windowName);
	~Window();

	void addDrawable(Drawable* drawable);

	void show();

	//callbacks
	void addCursorCallback(GLFWcursorposfun cursorCallback);
	void addScrollCallback(GLFWscrollfun scrollCallback);
	void addKeyboardCallback(std::function<void(GLFWwindow*)> keyboardCallback);
};
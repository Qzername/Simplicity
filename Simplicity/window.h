#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <list>

#include "initializationTools.h"
#include "shaderCompiling.h"
#include "drawable.h"
#include "camera.h"

class Window
{
	std::list<Drawable*> objectList;

	GLFWwindow* window;
	unsigned int shaderProgram;

public:
	Camera camera;

	Window(const char* windowName);
	~Window();

	void show();
	void addDrawable(Drawable* drawable);
};
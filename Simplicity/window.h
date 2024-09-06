#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <list>

#include "initializationTools.h"
#include "shaderCompiling.h"
#include "drawable.h"

class Window
{
	std::list<Drawable*> objectList;

	GLFWwindow* window;
	unsigned int shaderProgram;

public:
	Window(const char* windowName);
	~Window();

	void show();
	void addDrawable(Drawable* drawable);
};
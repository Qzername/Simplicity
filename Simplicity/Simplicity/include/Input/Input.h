#pragma once

#include "coreDefinitions.h"

#include <GLFW/glfw3.h>

#include <Vector2.h>

#include "KeyCode.h"
#include "KeyStatus.h"
#include "MouseKeyCode.h"

class CPP_LIB_EXP Input {
	GLFWwindow* window;

public:
	Input();
	Input(GLFWwindow* window);

	//TODO: thesse should start with captial letters
	KeyStatus GetButton(KeyCode key);
	KeyStatus GetMouseButton(MouseKeyCode key);
	Vector2 GetCursorPosition();

	void setMouseInputMode(int value);
};
#pragma once
#include <GLFW/glfw3.h>

#include <Vector2.h>

#include "KeyCode.h"
#include "KeyStatus.h"
#include "MouseKeyCode.h"

class Input {
	GLFWwindow* window;

public:
	Input();
	Input(GLFWwindow* window);

	KeyStatus GetButton(KeyCode key);
	KeyStatus GetMouseButton(MouseKeyCode key);
	Vector2 GetCursorPosition();

	void setMouseInputMode(int value);
};
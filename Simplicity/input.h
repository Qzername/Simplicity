#pragma once
#include "vector2.h"

#include <GLFW/glfw3.h>

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
	vector2 GetCursorPosition();
};
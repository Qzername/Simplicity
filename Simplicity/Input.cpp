#include "Input.h"

Input::Input()
{
	window = nullptr;
}

Input::Input(GLFWwindow* window)
{
	this->window = window;
}

KeyStatus Input::GetButton(KeyCode key)
{
	return static_cast<KeyStatus>(glfwGetKey(window, static_cast<int>(key)));
}

KeyStatus Input::GetMouseButton(MouseKeyCode key)
{
	return static_cast<KeyStatus>(glfwGetMouseButton(window, static_cast<int>(key)));
}

vector2 Input::GetCursorPosition()
{
	double xPos, yPos;
	glfwGetCursorPos(window, &xPos, &yPos);
	return vector2(xPos, yPos);
}
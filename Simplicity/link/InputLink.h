#pragma once

#define EXPORT __declspec(dllexport)

#include <Input/input.h>

extern "C" {
	EXPORT KeyStatus Input_getButton(Input* input, KeyCode key) {
		return input->GetButton(key);
	}

	EXPORT KeyStatus Input_getMouseButton(Input* input, MouseKeyCode key) {
		return input->GetMouseButton(key);
	}

	EXPORT Vector2 Input_getCursorPosition(Input* input) {
		return input->GetCursorPosition();
	}

	EXPORT void Input_setMouseInputMode(Input* input, int value) {
		input->setMouseInputMode(value);
	}
}
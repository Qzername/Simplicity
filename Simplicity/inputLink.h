#pragma once

#define EXPORT __declspec(dllexport)

#include "input.h"

extern "C" {
	EXPORT KeyStatus Input_getButton(Input* input, KeyCode key) {
		return input->GetButton(key);
	}

	EXPORT KeyStatus Input_getMouseButton(Input* input, MouseKeyCode key) {
		return input->GetMouseButton(key);
	}

	EXPORT vector2 Input_getMousePosition(Input* input) {
		return input->GetCursorPosition();
	}
}
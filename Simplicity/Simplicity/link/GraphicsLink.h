#pragma once

#define EXPORT __declspec(dllexport)

#include <Graphics/Graphics.h>

extern "C" {
	EXPORT Camera* Graphics_getCamera(Graphics* graphics) {
		return &graphics->camera;
	}

	EXPORT Renderer* Graphics_getRenderer(Graphics* graphics) {
		return &graphics->renderer;
	}
}
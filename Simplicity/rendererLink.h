#pragma once

#define EXPORT __declspec(dllexport)

#include "renderer.h"

extern "C" {
	EXPORT Color Renderer_getBackgroundColor(Renderer* renderer)
	{
		return renderer->backgroundColor;
	}

	EXPORT void Renderer_setBackgroundColor(Renderer* renderer, Color color) {
		renderer->backgroundColor = color;
	}

	EXPORT void Renderer_render(Renderer* renderer, GraphicsObject graphicsObject) {
		renderer->Render(graphicsObject);
	}

	EXPORT void Renderer_clear(Renderer* renderer) {
		renderer->Clear();
	}
}
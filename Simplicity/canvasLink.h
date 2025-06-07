#pragma once

#define EXPORT __declspec(dllexport)

#include "canvas.h"

extern "C" {
	EXPORT Canvas* Canvas_create(Renderer* renderer)
	{
		return new Canvas(renderer);
	}

	EXPORT void Canvas_drawWheel(Canvas* canvas, vector3 center, float radius)
	{
		canvas->DrawWheel(center, radius);
	}

	EXPORT void Canvas_drawRectangle(Canvas* canvas, vector3 topLeft, vector3 bottomRight)
	{
		canvas->DrawRectangle(topLeft, bottomRight);
	}

	EXPORT void Canvas_drawCube(Canvas* canvas, vector3 center)
	{
		canvas->DrawCube(center);
	}
}
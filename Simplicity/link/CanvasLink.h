#pragma once

#define EXPORT __declspec(dllexport)

#include <Graphics/Tools/Canvas.h>

extern "C" {
	EXPORT Canvas* Canvas_create(Renderer* renderer)
	{
		return new Canvas(renderer);
	}

	EXPORT void Canvas_drawWheel(Canvas* canvas, Vector3 center, float radius)
	{
		canvas->DrawWheel(center, radius);
	}

	EXPORT void Canvas_drawRectangle(Canvas* canvas, Vector3 topLeft, Vector3 bottomRight)
	{
		canvas->DrawRectangle(topLeft, bottomRight);
	}

	EXPORT void Canvas_drawCube(Canvas* canvas, Vector3 center)
	{
		canvas->DrawCube(center);
	}
}
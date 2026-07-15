#pragma once

#include "coreDefinitions.h"

#include <Vector3.h>
#include <Graphics/Renderer.h>

class CPP_LIB_EXP Canvas {
	Renderer* renderer;
public:
	Canvas();
	Canvas(Renderer* renderer);

	void DrawWheel(Vector3 center, float radius);
	void DrawRectangle(Vector3 topLeft, Vector3 bottomRight);
	void DrawCube(Vector3 center);
};
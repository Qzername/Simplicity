#pragma once

#include "vector3.h"
#include "geometry.h"
#include "transform.h"
#include "color.h"
#include "graphicsObject.h"
#include "renderer.h"
#include "brush.h"

#include <vector>

class Canvas {
	Renderer* renderer;
public:
	Canvas();
	Canvas(Renderer* renderer);

	void DrawWheel(vector3 center, float radius);
	void DrawRectangle(vector3 topLeft, vector3 bottomRight);
	void DrawCube(vector3 center);
};
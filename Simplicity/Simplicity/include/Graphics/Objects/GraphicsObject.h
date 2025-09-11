#pragma once

#include "Color.h"
#include "Transform.h"
#include "Texture2D.h"
#include "Geometry.h"

class GraphicsObject {
	void calculateTransform(unsigned int shaderProgram);

public:
	Color color;
	Transform transform;
	Texture2D* texture;
	Geometry* geometry;

	void render(unsigned int shaderProgram);
};
#pragma once

#include "color.h"
#include "transform.h"
#include "texture2D.h"
#include "geometry.h"

class GraphicsObject {
	void calculateTransform(unsigned int shaderProgram);

public:
	Color color;
	Transform transform;
	Texture2D* texture;
	Geometry geometry;

	void render(unsigned int shaderProgram);
};
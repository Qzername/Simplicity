#pragma once

#include "coreDefinitions.h"

#include "Color.h"
#include "Transform.h"
#include "Texture2D.h"
#include "Geometry.h"

class CPP_LIB_EXP GraphicsObject {
	void calculateTransform(unsigned int shaderProgram);

public:
	Color color;
	Transform transform;
	Texture2D* texture;
	Geometry* geometry;

	void render(unsigned int shaderProgram);
};
#pragma once
#include "vector3.h"
#include "color.h"
#include "transform.h"

class Drawable
{
public:
	Transform transform;
	Color color;

	Drawable(float x, float y);

	virtual void Render(unsigned int shaderProgram) = 0;
};
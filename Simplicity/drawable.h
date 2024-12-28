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

	//TODO: I should standardize this somehow, so cube and rectangle can use the same method
	virtual void Render(unsigned int shaderProgram) = 0;
};
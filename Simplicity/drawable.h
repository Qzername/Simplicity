#pragma once
#include "vector3.h"
#include "color.h"

class Drawable
{
public:
	vector3 position;
	Color color;

	Drawable(float x, float y);

	virtual void Render() = 0;
};
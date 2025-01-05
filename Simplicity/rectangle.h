#pragma once
#include <glad/glad.h>

#include "drawable.h"

class Rectangle : public Drawable
{
	float width, height;

public:
	Rectangle(float x, float y, float width, float height);

	float getWidth();
	void setWidth(float width);

	float getHeight();
	void setHeight(float height);

private:
	unsigned int GenerateVAO();
};
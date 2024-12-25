#pragma once
#include <glad/glad.h>

#include "drawable.h"

class Rectangle : public Drawable
{
public:
	float width, height;

private:
	unsigned int VAO;
	unsigned int GenerateVAO();

public:
	Rectangle(float x, float y, float width, float height);

	void Render(unsigned int shaderProgram);
};
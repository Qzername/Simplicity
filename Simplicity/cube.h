#pragma once
#include <glad/glad.h>

#include "drawable.h"

class Cube : public Drawable {
public:
	float size;

	Cube(vector3 position, float size);

	void Render(unsigned int shaderProgram);

private:
	unsigned int VAO;
	unsigned int GenerateVAO();
};
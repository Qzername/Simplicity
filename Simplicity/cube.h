#pragma once
#include <glad/glad.h>

#include "drawable.h"

class Cube : public Drawable {
public:
	Cube(vector3 position);

	void Render(unsigned int shaderProgram);

private:
	unsigned int VAO;
	unsigned int GenerateVAO();
};
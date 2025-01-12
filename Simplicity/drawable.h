#pragma once
#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "vector3.h"
#include "color.h"
#include "transform.h"

class Drawable
{
protected:
	unsigned int VAO;	
	unsigned int amountOfVertices;

	void calculateTransform(unsigned int shaderProgram);
public:
	Transform transform;
	Color color;

	Drawable(float x, float y);

	virtual void render(unsigned int shaderProgram);
};
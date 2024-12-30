#pragma once
#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "transform.h"

class Camera {
	unsigned int shaderProgramID;

public:
	Transform transform;
	float FOV = 45.0f;

	void Config(unsigned int shaderProgramID);
	void CalculateTransformations();
};
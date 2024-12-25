#pragma once
#include <glad/glad.h>

#include "transform.h"

class Camera {
public:
	Transform transform;
	float FOV = 45.0f;

	void Config(unsigned int shaderProgramID);
	void CalculateTransformations();

private:
	unsigned int shaderProgramID;
};
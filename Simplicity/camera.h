#pragma once
#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "transform.h"

class Camera {
	unsigned int shaderProgramID;

public:
	//TODO: directions should be calculated and located in Transform whenever the positon/rotation is changed
	vector3 cameraUp = vector3(0.0f, 1.0f, 0.0f);
	vector3 cameraFront = vector3(0.0f, 0.0f, -1.0f);
	vector3 cameraRight = vector3(1.0f, 0.0f, 0.0f);

	Transform transform;
	float FOV = 45.0f;

	void Config(unsigned int shaderProgramID);
	void CalculateTransformations();
};
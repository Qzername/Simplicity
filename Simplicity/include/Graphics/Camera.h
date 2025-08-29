#pragma once

#include <Graphics/Objects/Transform.h>

class Camera {
	unsigned int shaderProgramID;

public:
	Transform transform;
	float FOV = 45.0f;

	void Config(unsigned int shaderProgramID);
	void CalculateTransformations();
};
#pragma once

#include "coreDefinitions.h"

#include <Graphics/Objects/Transform.h>

class CPP_LIB_EXP Camera {
	unsigned int shaderProgramID;

public:
	Transform transform;
	float FOV = 45.0f;

	void Config(unsigned int shaderProgramID);
	void CalculateTransformations();
};
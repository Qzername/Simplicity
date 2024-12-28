#pragma once

#include <string.h>
#include "window.h"
#include "camera.h"

extern "C" {
	__declspec(dllexport) float Camera_getFOV(Camera* camera)
	{
		return camera->FOV;
	}

	__declspec(dllexport) void Camera_setFOV(Camera* camera, float FOV)
	{
		camera->FOV = FOV;
	}

	__declspec(dllexport) Transform* Camera_getTransform(Camera* camera)
	{
		return &camera->transform;
	}

	__declspec(dllexport) vector3 Camera_getDirections(Camera* camera, const char* directionName)
	{
		std::string property(directionName);

		if (property == "cameraUp")
			return camera->cameraUp;
		else if (property == "cameraFront")
			return camera->cameraFront;
		else if (property == "cameraRight")
			return camera->cameraRight;
		else
			throw std::invalid_argument("Invalid direction name");
	}
}
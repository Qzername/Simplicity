#pragma once

#include <Graphics/Camera.h>

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
}
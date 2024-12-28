#pragma once

#include "window.h"
#include "camera.h"

extern "C" {
	__declspec(dllexport) Camera* getCamera(Window* window)
	{
		return &window->camera;
	}

	__declspec(dllexport) void setCameraFOV(Camera* camera, float FOV)
	{
		camera->FOV = FOV;
	}

	__declspec(dllexport) void setCameraPosition(Camera* camera, vector3 position)
	{
		camera->transform.position = position;
	}

	__declspec(dllexport) void setCameraRotation(Camera* camera, vector3 rotation)
	{
		camera->transform.rotation = rotation;
	}
}
#pragma once

#include <string.h>
#include <stdexcept>
#include "transform.h"

extern "C" {
	__declspec(dllexport) vector3 Transform_getProperty(Transform* transform, const char* name)
	{
		std::string property(name);

		if (property == "position")
			return transform->position;
		else if (property == "rotation")
			return transform->rotation;
		else
			throw std::invalid_argument("Invalid property name");
	}

	__declspec(dllexport) void Transform_setProperty(Transform* transform, const char* name, vector3 value)
	{
		std::string property(name);

		if (property == "position")
			transform->position = value;
		else if (property == "rotation")
			transform->rotation = value;
		else 
			throw std::invalid_argument("Invalid property name");
	}
}
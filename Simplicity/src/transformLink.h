#pragma once

#include <string.h>
#include <stdexcept>
#include "transform.h"

extern "C" {
	__declspec(dllexport) vector3 Transform_getProperty(Transform* transform, const char* name)
	{
		std::string property(name);

		if (property == "position")
			return transform->getPosition();
		else if (property == "eulerRotation")
			return transform->getEulerRotation();
		else if (property == "scale")
			return transform->scale;
		else if (property == "forward")
			return transform->getForward();
		else if (property == "right")
			return transform->getRight();
		else if (property == "up")
			return transform->getUp();
		else
			throw std::invalid_argument("Invalid property name");
	}

	__declspec(dllexport) void Transform_setProperty(Transform* transform, const char* name, vector3 value)
	{
		std::string property(name);

		if (property == "position")
			transform->setPosition(value);
		else if (property == "eulerRotation")
			transform->setEulerRotation(value);
		else if (property == "scale")
			transform->scale = value;
		else 
			throw std::invalid_argument("Invalid property name");
	}

	__declspec(dllexport) quaternion Transform_getQuaternion(Transform* transform) {
		return transform->getRotation();
	}

	__declspec(dllexport) void Transform_setQuaternion(Transform* transform, quaternion rotation) {
		transform->setRotation(rotation);
	}
}
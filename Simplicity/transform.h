#pragma once
#include "vector3.h"

class Transform {
public:
	vector3 position;
	vector3 rotation; //euler angles, TODO: add quaternions support

	Transform();
	Transform(vector3 position);
	Transform(vector3 position, vector3 rotation);
};
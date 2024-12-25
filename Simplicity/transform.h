#pragma once
#include "vector3.h"

//this is a class because in future
//it will have methods
class Transform {
public:
	vector3 position;
	vector3 rotation; //euler angles, TODO: add quaternions support
	//TODO: add scale

	Transform();
	Transform(vector3 position);
	Transform(vector3 position, vector3 rotation);
};
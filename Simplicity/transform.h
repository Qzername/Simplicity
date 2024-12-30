#pragma once
#include "vector3.h"

//this is a class because in future
//it will have methods
class Transform {
	vector3 position;
	vector3 rotation; //euler angles, TODO: add quaternions support
	//add scale

	vector3 forward;
	vector3 right;
	vector3 up;

	void calculateDirections();
public:
	
	vector3 getPosition();
	void setPosition(vector3 position);
	vector3 getRotation();
	void setRotation(vector3 rotation);

	vector3 getForward();
	vector3 getRight();
	vector3 getUp();

	Transform();
	Transform(vector3 position);
	Transform(vector3 position, vector3 rotation);
};
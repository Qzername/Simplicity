#pragma once
#include "vector3.h"
#include "quaternion.h"

//this is a class because in future
//it will have methods
class Transform {
	vector3 position;
	
	//rotation
	quaternion rotation; 

	vector3 forward;
	vector3 right;
	vector3 up;

	void calculateDirections();
public:
	vector3 scale;

	//TODO: fix this mess
	vector3 getPosition();
	void setPosition(vector3 position);

	quaternion getRotation();
	void setRotation(quaternion rotation);
	vector3 getEulerRotation();
	void setEulerRotation(vector3 rotation);

	vector3 getForward();
	vector3 getRight();
	vector3 getUp();

	Transform();
	Transform(vector3 position);
	Transform(vector3 position, vector3 rotation);
};
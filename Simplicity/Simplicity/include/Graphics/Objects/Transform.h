#pragma once
#include <Vector3.h>
#include <Quaternion.h>

//this is a class because in future
//it will have methods
class Transform {
	Vector3 position;
	
	//rotation
	Quaternion rotation;

	Vector3 forward;
	Vector3 right;
	Vector3 up;

	void calculateDirections();
public:
	Vector3 scale;

	//TODO: fix this mess
	Vector3 getPosition();
	void setPosition(Vector3 position);

	Quaternion getRotation();
	void setRotation(Quaternion rotation);
	Vector3 getEulerRotation();
	void setEulerRotation(Vector3 rotation);

	Vector3 getForward();
	Vector3 getRight();
	Vector3 getUp();

	Transform();
	Transform(Vector3 position);
	Transform(Vector3 position, Vector3 rotation);
};
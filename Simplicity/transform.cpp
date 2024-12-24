#include "transform.h"

Transform::Transform(vector3 position, vector3 rotation) {
	this->position = position;
	this->rotation = rotation;
}

Transform::Transform(vector3 position) : Transform(position, vector3(0,0,0)) {

}

Transform::Transform() : Transform(vector3(0,0,0), vector3(0, 0, 0)) {

}

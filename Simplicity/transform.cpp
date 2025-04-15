#pragma once
#include "transform.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>

void Transform::calculateDirections() {
	glm::vec3 position = glm::vec3(this->position.x, this->position.y, this->position.z);
	
	glm::vec3 rotationEuler = glm::vec3(glm::radians(this->rotation.x), glm::radians(this->rotation.y), glm::radians(this->rotation.z));
	glm::quat quaternion = glm::quat(rotationEuler);

	glm::vec3 forward = quaternion * glm::vec3(0, 0, 1);
	glm::vec3 up = quaternion * glm::vec3(0, 1, 0);
	glm::vec3 right = quaternion * glm::vec3(1, 0, 0);

	this->forward = vector3(forward.x, forward.y, forward.z);
	this->up = vector3(up.x, up.y, up.z);
	this->right = vector3(right.x, right.y, right.z);
}

vector3 Transform::getPosition() {
	return position;
}

void Transform::setPosition(vector3 position) {
	this->position = position;
	calculateDirections();
}

vector3 Transform::getRotation() {
	return rotation;
}

void Transform::setRotation(vector3 rotation) {
	this->rotation = rotation;
	calculateDirections();
}

vector3 Transform::getForward() {
	return forward;
}

vector3 Transform::getRight() {
	return right;
}

vector3 Transform::getUp() {
	return up;
}

Transform::Transform(vector3 position, vector3 rotation) {
	scale = vector3(1, 1, 1);
	this->position = position;
	this->rotation = rotation;

	calculateDirections();
}

Transform::Transform(vector3 position) : Transform(position, vector3(0,0,0)) {
}

Transform::Transform() : Transform(vector3(0,0,0), vector3(0, 0, 0)) {
}
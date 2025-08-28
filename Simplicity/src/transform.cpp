#pragma once
#include "transform.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>

void Transform::calculateDirections() {
	glm::vec3 position = glm::vec3(this->position.x, this->position.y, this->position.z);
	
	glm::quat quaternion = glm::quat(rotation.w, rotation.x, rotation.y, rotation.z);
	
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

// --- rotation ---

quaternion Transform::getRotation() {
	return rotation;
}

void Transform::setRotation(quaternion rotation) {
	this->rotation = rotation;
}

vector3 Transform::getEulerRotation() {
	glm::quat quaternion = glm::quat(rotation.w, rotation.x, rotation.y, rotation.z);
	glm::vec3 euler = glm::degrees(glm::eulerAngles(quaternion));
	return vector3(euler.x, euler.y, euler.z);
}

void Transform::setEulerRotation(vector3 rotation) {
	glm::vec3 euler = glm::radians(glm::vec3(rotation.x, rotation.y, rotation.z));
	glm::quat quat = glm::quat(euler);
	this->rotation = quaternion(quat.w, quat.x, quat.y, quat.z);

	calculateDirections();
}

// --- directions ---

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
	setEulerRotation(rotation);

	calculateDirections();
}

Transform::Transform(vector3 position) : Transform(position, vector3(0,0,0)) {
}

Transform::Transform() : Transform(vector3(0,0,0), vector3(0, 0, 0)) {
}
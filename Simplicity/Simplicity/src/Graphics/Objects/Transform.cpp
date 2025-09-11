#pragma once
#include <Graphics/Objects/Transform.h>

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

	this->forward = Vector3(forward.x, forward.y, forward.z);
	this->up = Vector3(up.x, up.y, up.z);
	this->right = Vector3(right.x, right.y, right.z);
}

Vector3 Transform::getPosition() {
	return position;
}

void Transform::setPosition(Vector3 position) {
	this->position = position;
	calculateDirections();
}

// --- rotation ---

Quaternion Transform::getRotation() {
	return rotation;
}

void Transform::setRotation(Quaternion rotation) {
	this->rotation = rotation;
}

Vector3 Transform::getEulerRotation() {
	glm::quat quaternion = glm::quat(rotation.w, rotation.x, rotation.y, rotation.z);
	glm::vec3 euler = glm::degrees(glm::eulerAngles(quaternion));
	return Vector3(euler.x, euler.y, euler.z);
}

void Transform::setEulerRotation(Vector3 rotation) {
	glm::vec3 euler = glm::radians(glm::vec3(rotation.x, rotation.y, rotation.z));
	glm::quat quat = glm::quat(euler);
	this->rotation = Quaternion(quat.w, quat.x, quat.y, quat.z);

	calculateDirections();
}

// --- directions ---

Vector3 Transform::getForward() {
	return forward;
}

Vector3 Transform::getRight() {
	return right;
}

Vector3 Transform::getUp() {
	return up;
}

Transform::Transform(Vector3 position, Vector3 rotation) {
	scale = Vector3(1, 1, 1);
	this->position = position;
	setEulerRotation(rotation);

	calculateDirections();
}

Transform::Transform(Vector3 position) : Transform(position, Vector3(0,0,0)) {
}

Transform::Transform() : Transform(Vector3(0,0,0), Vector3(0, 0, 0)) {
}
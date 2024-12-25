#include "camera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void Camera::Config(unsigned int shaderProgramID) {
	this->shaderProgramID = shaderProgramID;
}

void Camera::CalculateTransformations()
{
	vector3 pos = transform.position;

	glm::mat4 view = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(FOV), (float)800 / (float)600, 0.1f, 100.0f);
	view = glm::translate(view, glm::vec3(pos.x, pos.y, pos.z));

	unsigned int viewLoc = glGetUniformLocation(shaderProgramID, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

	unsigned int projectionLoc = glGetUniformLocation(shaderProgramID, "projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
}
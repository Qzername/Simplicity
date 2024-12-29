#include "camera.h"

void Camera::Config(unsigned int shaderProgramID) {
	this->shaderProgramID = shaderProgramID;
}

void Camera::CalculateTransformations()
{
	glm::vec3 cameraUpGLM = glm::vec3(cameraUp.x, cameraUp.y, cameraUp.z);
	glm::vec3 cameraFrontGLM = glm::vec3(cameraFront.x, cameraFront.y, cameraFront.z);

	glm::vec3 front;
	front.x = cos(glm::radians(transform.rotation.z)) * cos(glm::radians(transform.rotation.y));
	front.y = sin(glm::radians(transform.rotation.y));
	front.z = sin(glm::radians(transform.rotation.z)) * cos(glm::radians(transform.rotation.y));
	cameraFrontGLM = glm::normalize(front);

	vector3 pos = transform.position;

	glm::mat4 view = glm::mat4(1.0f); 
	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(FOV), (float)800 / (float)600, 0.1f, 100.0f);

	glm::vec3 glmPos = glm::vec3(pos.x, pos.y, pos.z);

	view = glm::translate(view, glmPos);

	view = glm::lookAt(glmPos, glmPos + cameraFrontGLM, cameraUpGLM);

	unsigned int viewLoc = glGetUniformLocation(shaderProgramID, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

	unsigned int projectionLoc = glGetUniformLocation(shaderProgramID, "projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

	cameraUp = vector3(cameraUpGLM.x, cameraUpGLM.y, cameraUpGLM.z);
	cameraFront = vector3(cameraFrontGLM.x, cameraFrontGLM.y, cameraFrontGLM.z);

	//right
	glm::vec3 cameraRightGLM = glm::normalize(glm::cross(cameraFrontGLM, cameraUpGLM));
	cameraRight = vector3(cameraRightGLM.x, cameraRightGLM.y, cameraRightGLM.z);
}
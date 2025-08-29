#include <Graphics/Camera.h>

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


void Camera::Config(unsigned int shaderProgramID) {
	this->shaderProgramID = shaderProgramID;
}

void Camera::CalculateTransformations()
{
	//projection
	glm::mat4 projection = glm::perspective(glm::radians(FOV), (float)800 / (float)600, 0.1f, 100.0f);

	unsigned int projectionLoc = glGetUniformLocation(shaderProgramID, "projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
	
	//view
	Vector3 pos = transform.getPosition();
	glm::vec3 glmPos = glm::vec3(pos.x, pos.y, pos.z);
	
	Vector3 forward = transform.getForward();
	glm::vec3 glmForward = glm::vec3(forward.x, forward.y, forward.z);

	Vector3 up = transform.getUp();
	glm::vec3 glmUp = glm::vec3(up.x, up.y, up.z);

	glm::mat4 view = glm::lookAt(glmPos, glmPos + glmForward, glmUp);

	unsigned int viewLoc = glGetUniformLocation(shaderProgramID, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
}
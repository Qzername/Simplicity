#include "graphicsObject.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

void GraphicsObject::render(unsigned int shaderProgram) {
    calculateTransform(shaderProgram);

    for (auto& mesh : geometry->meshes)
        mesh.render(shaderProgram);
}

void GraphicsObject::calculateTransform(unsigned int shaderProgram) {
    //color
    int vertexColorLocation = glGetUniformLocation(shaderProgram, "color");
    glUniform4f(vertexColorLocation, color.r / 255, color.g / 255, color.b / 255, color.w / 255);

    // --- transform --- 
    glm::mat4 transformMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first

    vector3 position = transform.getPosition();
    quaternion rotation = transform.getRotation();

    //position
    glm::vec3 glmPos = glm::vec3(position.x, position.y, position.z);
    transformMatrix = glm::translate(transformMatrix, glmPos);

    //rotation
    glm::quat quaternion = glm::quat(rotation.w, rotation.x, rotation.y, rotation.z);
    glm::mat4 rotationMatrix = glm::mat4_cast(quaternion);
    transformMatrix *= rotationMatrix;

    //scale
    glm::vec3 glmScale = glm::vec3(transform.scale.x, transform.scale.y, transform.scale.z);
    transformMatrix = glm::scale(transformMatrix, glmScale);

    unsigned int transformLoc = glGetUniformLocation(shaderProgram, "transform");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transformMatrix));
}
#include "drawable.h"
#include "color.h"

Drawable::Drawable(float x, float y){
    vector3 position;
    
    position.x = x;
    position.y = y;
    position.z = 0;

    this->transform = Transform(position);

    //default color (white)
    Color color;
    this->color = color;
}

void Drawable::Render(unsigned int shaderProgram) {
    //color
    int vertexColorLocation = glGetUniformLocation(shaderProgram, "color");
    glUniform4f(vertexColorLocation, color.r / 255, color.g / 255, color.b / 255, color.w / 255);

    //transform
    glm::mat4 transformMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first

    vector3 position = transform.getPosition();
    vector3 rotationEuler = transform.getRotation();

    glm::vec3 glmPos = glm::vec3(position.x, position.y, position.z);
    transformMatrix = glm::translate(transformMatrix, glmPos);

    glm::vec3 rotationEulerRadians = glm::vec3(glm::radians(rotationEuler.x), glm::radians(rotationEuler.y), glm::radians(rotationEuler.z));
    glm::quat rotation = glm::quat(rotationEulerRadians);
    glm::mat4 rotationMatrix = glm::mat4_cast(rotation);
    transformMatrix *= rotationMatrix;

    unsigned int transformLoc = glGetUniformLocation(shaderProgram, "transform");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transformMatrix));

    //draw
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, amountOfVertices, GL_UNSIGNED_INT, 0);
}
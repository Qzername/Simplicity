#include "rectangle.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

Rectangle::Rectangle(float x, float y, float width, float height) : Drawable(x, y) {
    this->width = width;
    this->height = height;
    
    VAO = GenerateVAO();
}

unsigned int Rectangle::GenerateVAO() {
    vector3 position = transform.getPosition();
    int x = position.x;
    int y = position.y;

    float vertices[] = { //pos + texture cords
        x+width,  y+height, 0.0f, 1.0f, 1.0f,  // top right 
        x+width,  y,        0.0f, 1.0f, 0.0f,  // bottom right
        x,        y,        0.0f, 0.0f, 0.0f, // bottom left
        x,        y+height, 0.0f, 0.0f, 1.0f   // top left 
    };
    unsigned int indices[] = {  
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };

    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    return VAO;
}

void Rectangle::Render(unsigned int shaderProgram) {

    //color
    int vertexColorLocation = glGetUniformLocation(shaderProgram, "color");
    glUniform4f(vertexColorLocation,color.r/255, color.g/255, color.b/255, color.w/255);
    
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
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
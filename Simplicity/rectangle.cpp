#include "rectangle.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

Rectangle::Rectangle(float x, float y, float width, float height) : Drawable(x, y) {
    this->width = width;
    this->height = height;
    
    VAO = GenerateVAO();
}

unsigned int Rectangle::GenerateVAO() {
    int x = transform.position.x;
    int y = transform.position.y;

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
    glUniform4f(vertexColorLocation,color.r, color.g, color.b, color.w);
    
    //transform
    glm::mat4 transformMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    
    glm::vec3 glmPos = glm::vec3(transform.position.x, transform.position.y, transform.position.z);
    transformMatrix = glm::translate(transformMatrix, glmPos);

    transformMatrix = glm::rotate(transformMatrix, transform.rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    transformMatrix = glm::rotate(transformMatrix, transform.rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
    transformMatrix = glm::rotate(transformMatrix, transform.rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));

    unsigned int transformLoc = glGetUniformLocation(shaderProgram, "transform");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transformMatrix));

    //draw
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
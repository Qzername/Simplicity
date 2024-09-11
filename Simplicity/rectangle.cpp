#include "rectangle.h"

#include<iostream>

Rectangle::Rectangle(float x, float y, float width, float height) : Drawable(x, y) {
    this->width = width;
    this->height = height;
    
    VAO = GenerateVAO();
}

unsigned int Rectangle::GenerateVAO() {
    int x = position.x;
    int y = position.y;

    float vertices[] = {
        x+width,  y+height, 0.0f,  // top right
        x+width,  y,        0.0f,  // bottom right
        x,        y,        0.0f,  // bottom left
        x,        y+height, 0.0f   // top left 
    };
    unsigned int indices[] = {  
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };

    float colors[] = {
        color.r, color.g, color.b, color.w,
        color.r, color.g, color.b, color.w,
        color.r, color.g, color.b, color.w,
        color.r, color.g, color.b, color.w,
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

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    return VAO;
}

void Rectangle::Render() {
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
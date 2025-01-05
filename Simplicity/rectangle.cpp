#include "rectangle.h"

Rectangle::Rectangle(float x, float y, float width, float height) : Drawable(x, y) {
    this->width = width;
    this->height = height;
    
	amountOfVertices = 6;
    VAO = GenerateVAO();
}

float Rectangle::getWidth() {
	return width;
}

void Rectangle::setWidth(float width) {
	this->width = width;

    glDeleteVertexArrays(1, &VAO);
	VAO = GenerateVAO();
}

float Rectangle::getHeight() {
	return height;
}

void Rectangle::setHeight(float height) {
	this->height = height;

    glDeleteVertexArrays(1, &VAO);
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
        0, 1, 3, 
        1, 2, 3  
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
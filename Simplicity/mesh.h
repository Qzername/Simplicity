#pragma once
#include <glad/glad.h> // holds all OpenGL type declarations

#include <string>
#include <vector>

#include "vertex.h"
#include "drawable.h"

using namespace std;

class Mesh : public Drawable {
    unsigned int VBO, EBO;
    unsigned int VAO;

    vector<Vertex>       vertices;
    vector<unsigned int> indices;

public:
    Mesh(vector<Vertex> vertices, vector<unsigned int> indices);
    void render(unsigned int shaderProgram);
};
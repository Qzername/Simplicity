#pragma once
#include <glad/glad.h> // holds all OpenGL type declarations

#include <string>
#include <vector>

#include "vertex.h"

using namespace std;

class Mesh {
    unsigned int VBO, EBO;
    unsigned int VAO;

    vector<Vertex>       vertices;
    vector<unsigned int> indices;

public:
    Mesh(vector<Vertex> vertices, vector<unsigned int> indices);
    void render(unsigned int shaderProgram);
};
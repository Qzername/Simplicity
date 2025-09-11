#pragma once

#include <vector>

#include <Graphics/Vertex.h>

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
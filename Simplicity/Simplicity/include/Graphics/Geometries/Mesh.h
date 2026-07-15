#pragma once

#include "coreDefinitions.h"

#include <vector>

#include <Graphics/Vertex.h>

using namespace std;

class CPP_LIB_EXP Mesh {
    unsigned int VBO, EBO;
    unsigned int VAO;

    vector<Vertex>       vertices;
    vector<unsigned int> indices;

public:
    Mesh(vector<Vertex> vertices, vector<unsigned int> indices);
    void render(unsigned int shaderProgram);
};
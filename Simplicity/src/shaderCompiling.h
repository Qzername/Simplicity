#pragma once

#include <glad/glad.h>

#include <iostream>
#include <fstream>
#include <filesystem>

#include <string>
#include <vector>

using namespace std;
namespace fs = std::filesystem;

enum ShaderType {
    VERTEX,
    FRAGMENT
};

struct shaderInfo {
    ShaderType type;
    string content;
};

vector<shaderInfo> loadDefaultShaders();
vector<shaderInfo> readShaders();
unsigned int compileShaders(vector<shaderInfo> shaders);
#pragma once

#include <glad/glad.h>

#include <iostream>
#include <fstream>
#include <filesystem>

#include <string>

using namespace std;
namespace fs = std::filesystem;

enum ShaderType {
    VERTEX,
    FRAGMENT
};

struct shaderInfo {
    ShaderType type;
    const char* content;
};

void readShaders();
unsigned int compileShaders();
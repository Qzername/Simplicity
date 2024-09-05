#include "shaderCompiling.h"

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

vector<shaderInfo> readShaders()
{
    vector<shaderInfo> shaders;

    for (const auto& entry : fs::directory_iterator("./Shaders/"))
    {
        string output, temp;
        string path = entry.path().string();

        ifstream shaderFile(path);

        while (getline(shaderFile, temp)) {
            output += temp + '\n';
        }

        shaderInfo shader;
        shader.type = VERTEX;

        if (path.ends_with(".frag"))
            shader.type = FRAGMENT;

        shader.content = output;

        shaders.push_back(shader);
    }

    return shaders;
}

unsigned int compileShaders(vector<shaderInfo> shaders) {
    unsigned int shaderProgram = glCreateProgram();
    unsigned int shadersAdrs[2];

    for (int i = 0; i < 2; i++)
    {
        int shaderType = 0;

        shaderInfo currentShader = shaders[i];

        if (currentShader.type == VERTEX)
            shaderType = GL_VERTEX_SHADER;
        else
            shaderType = GL_FRAGMENT_SHADER;

        unsigned int shader = glCreateShader(shaderType);
        shadersAdrs[i] = shader;

        const char* c_str = currentShader.content.c_str();

        glShaderSource(shader, 1, &c_str, NULL);
        glCompileShader(shader);

        checkForCompilationErrors(shader);

        glAttachShader(shaderProgram, shader);
    }

    glLinkProgram(shaderProgram);

    for (int i = 0; i < 2; i++)
        glDeleteShader(shadersAdrs[i]);

    return shaderProgram;
}

void checkForCompilationErrors(unsigned int shaderAdrs)
{
    int  success;
    char infoLog[512];
    glGetShaderiv(shaderAdrs, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(shaderAdrs, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

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

shaderInfo* readShaders()
{
    //future me problem ig
    shaderInfo shaders[2];

    int i = 0;

    for (const auto& entry : fs::directory_iterator("./Shaders/"))
    {
        string output, temp;
        string path = entry.path().string();

        ifstream shaderFile(path);

        while (getline(shaderFile, temp)) {
            output += temp;
        }

        shaderInfo shader;
        shader.type = VERTEX;

        if (path.ends_with(".frag"))
            shader.type = FRAGMENT;

        cout << output << endl;

        shader.content = output;

        shaders[i] = shader;
            
        i++;
    }

    cout << i << endl;

    cout << shaders[0].content << endl;

    return shaders;
}

unsigned int compileShaders(struct shaderInfo *shaders) {
    unsigned int shaderProgram = glCreateProgram();
    unsigned int shadersAdrs[2];

    cout << shaders[0].content << endl;

    return 0;

    for (int i = 0; i < 2; i++)//again, future me problem
    {
        int shaderType = 0;

        shaderInfo currentShader = shaders[i];

        return 0;

        if (currentShader.type == VERTEX)
            shaderType = GL_VERTEX_SHADER;
        else
            shaderType = GL_FRAGMENT_SHADER;

        unsigned int shader = glCreateShader(shaderType);
        shadersAdrs[i] = shader;

        const char* c_str = currentShader.content.c_str();

        glShaderSource(shader, 1, &c_str, NULL);
        glCompileShader(shader);

        glAttachShader(shaderProgram, shader);
    }

    glLinkProgram(shaderProgram);

    for (int i = 0; i < 2; i++)
        glDeleteShader(shadersAdrs[i]);

    return shaderProgram;
}

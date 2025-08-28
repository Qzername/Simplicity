#include "shaderCompiling.h"

void checkForCompilationErrors(unsigned int shaderAdrs);

vector<shaderInfo> loadDefaultShaders() {
    vector<shaderInfo> shaders;

    shaderInfo fragmentShader;
    fragmentShader.type = FRAGMENT;
    fragmentShader.content = R"frag(
        #version 330 core
        out vec4 FragColor;

        in vec2 TexCoord;

        uniform vec4 color;
        uniform sampler2D texture1;

        void main()
        {
           vec4 texColor = texture(texture1, TexCoord) * color;
           FragColor = vec4(texColor.rgb * color.rgb, texColor.a * color.a);
        }
    )frag";
    shaders.push_back(fragmentShader);

    shaderInfo vertexShader;
    vertexShader.type = VERTEX;
    vertexShader.content = R"vert(
        #version 330 core
        layout (location = 0) in vec3 aPos;
        layout (location = 1) in vec2 aTexCoord;

        out vec2 TexCoord;

        uniform mat4 transform;
        uniform mat4 view;
        uniform mat4 projection;

        void main()
        {
            gl_Position = projection * view * transform * vec4(aPos, 1.0);
	        TexCoord = vec2(aTexCoord.x, aTexCoord.y);
        }
    )vert";
    shaders.push_back(vertexShader);

    return shaders;
}

//TODO: do a better shader handling system
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

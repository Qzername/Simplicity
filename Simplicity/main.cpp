#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "initializationTools.h"
#include "shaderCompiling.h"

#include "rectangle.h"

void processInput(GLFWwindow* window);

int main()
{
    GLFWwindow* window = initializeGlfw("Simplicity test window");

    unsigned int shaderProgram = compileShaders();

    Rectangle rect(0.20f,0.20f,0.5f,0.5f);
    Rectangle rect2(-1.0f, -1.0f, 0.1f, 0.1f);

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);

        rect.Render();
        rect2.Render();

        glBindVertexArray(0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

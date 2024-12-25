#include "window.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

Window::Window(const char* windowName) {
    window = initializeGlfw(windowName);

    shaderProgram = compileShaders(readShaders());
    camera.Config(shaderProgram);
}

Window::~Window() {
    glfwTerminate();
}

void Window::show() {

    while (!glfwWindowShouldClose(window))
    {
        if (keyboardCallback)
            keyboardCallback(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!

        glUseProgram(shaderProgram);

        camera.CalculateTransformations(); // TODO: dont calculate transformations every frame

        for (auto d : objectList)
            d->Render(shaderProgram);

        glBindVertexArray(0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Window::addDrawable(Drawable* drawable) {
    objectList.push_back(drawable);
}

void Window::addCursorCallback(GLFWcursorposfun cursorCallback)
{
    glfwSetCursorPosCallback(window, cursorCallback);
}

void Window::addScrollCallback(GLFWscrollfun scrollCallback)
{
    glfwSetScrollCallback(window, scrollCallback);
}

void Window::addKeyboardCallback(std::function<void(GLFWwindow*)> keyboardCallback)
{
    this->keyboardCallback = keyboardCallback;
}
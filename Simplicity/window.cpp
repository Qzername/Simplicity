#include "window.h"

#include<iostream>

Window::Window(const char* windowName) {
    window = initializeGlfw(windowName);

    shaderProgram = compileShaders(readShaders());
}

Window::~Window() {
    glfwTerminate();
}

void Window::show() {
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);

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
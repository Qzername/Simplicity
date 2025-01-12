#include "window.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

Window::Window(const char* windowName) {
    window = initializeGlfw(windowName);

    shaderProgram = compileShaders(readShaders());
    camera.Config(shaderProgram);
    glUseProgram(shaderProgram);
}

Window::~Window() {
    glfwTerminate();
}

bool Window::shouldClose() {
	return glfwWindowShouldClose(window);
}

void Window::frameCalculations() {
	float currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;

    //TODO: move it somewhere else and dont calculate it every frame
    camera.CalculateTransformations();
}

void Window::clear(Color color) {
	glClearColor(color.r/255, color.g/255, color.b/255, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::draw(Drawable* drawable) {
	drawable->render(shaderProgram);
}

void Window::render() {
    glBindVertexArray(0);

    glfwSwapBuffers(window);
    glfwPollEvents();
}

int Window::getKey(int key) {
	return glfwGetKey(window, key);
}

vector3 Window::getCursorPos() {
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	return vector3(xpos, ypos, 0);
}   

void Window::setMouseInputMode(int value) {
	glfwSetInputMode(window, GLFW_CURSOR, value);
}

void Window::close() {
    glfwSetWindowShouldClose(window, true);
}
#include "window.h"
#include "texture2D.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Window::Window(const char* windowName) {
    window = initializeGlfw(windowName);

    shaderProgram = compileShaders(loadDefaultShaders());
    camera.Config(shaderProgram);
    glUseProgram(shaderProgram);

    //set default texture
    unsigned char textureData[] = {
        255,255,255
    };

    Texture2D defaultTexture = Texture2D::LoadFromData(1,1,textureData);
    defaultTexture.SetActive();
}

Window::~Window() {
    glfwTerminate();
}

void Window::show()
{
    while (!glfwWindowShouldClose(window))
    {
        frameCalculations();

        if(onFrame)
            onFrame();

        Color backgroundColor = scene.getBackgroundColor();
        glClearColor(backgroundColor.r/255, backgroundColor.g/255, backgroundColor.b/255, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        for (auto& obj : scene.objects)
            obj->render(shaderProgram);

        render();
    }
}

void Window::setOnFrameCallback(OnFrameCallback cb) {
    onFrame = cb;
}

void Window::frameCalculations() {
	float currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;

    //TODO: move it somewhere else and dont calculate it every frame
    camera.CalculateTransformations();
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
#include "Window.h"
#include <Graphics/Objects/Texture2D.h>
#include <InitializationTools.h>

Window::Window(const char* windowName) {
    window = initializeGlfw(windowName);

    graphics.Initialize();

    //set default texture
    unsigned char textureData[] = {
        255,255,255,
    };

    defaultTexture = Texture2D::LoadFromData(1, 1, textureData, TextureFormat::RGB);

    input = Input(window);
}

Window::~Window() {
    glfwTerminate();
}

void Window::show()
{
    defaultTexture.SetActive();
    while (!glfwWindowShouldClose(window))
    {
        frameCalculations();
        
        if (onFrame)
            onFrame();

        glBindVertexArray(0);

        glfwSwapBuffers(window);
        glfwPollEvents();
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
    graphics.camera.CalculateTransformations();
}

void Window::close() {
    glfwSetWindowShouldClose(window, true);
}
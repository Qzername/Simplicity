#pragma once
#include "window.h"

extern "C" {
	// fields and properties
	__declspec(dllexport) Camera* Window_getCamera(Window* window)
	{
		return &window->camera;
	}

	__declspec(dllexport) float Window_getDeltaTime(Window* window)
	{
		return window->deltaTime;
	}

	//constructors
	__declspec(dllexport) Window* Window_create(const char* windowName)
	{
		return new Window(windowName);
	}

	//functions
	__declspec(dllexport) bool Window_shouldClose(Window * window)
	{
		return window->shouldClose();
	}

	__declspec(dllexport) void Window_frameCalculations(Window* window)
	{
		window->frameCalculations();
	}

	__declspec(dllexport) void Window_clear(Window* window, Color color)
	{
		window->clear(color);
	}

	__declspec(dllexport) void Window_draw(Window* window, Drawable* drawable)
	{
		window->draw(drawable);
	}

	__declspec(dllexport) void Window_render(Window* window)
	{
		window->render();
	}

	__declspec(dllexport) int Window_getKey(Window* window, int key)
	{
		return window->getKey(key);
	}

	__declspec(dllexport) vector3 Window_getCursorPos(Window* window)
	{
		return window->getCursorPos();
	}

	__declspec(dllexport) void Window_setMouseInputMode(Window* window, int value)
	{
		window->setMouseInputMode(value);
	}

	__declspec(dllexport) void Window_close(Window* window)
	{
		window->close();
	}
}
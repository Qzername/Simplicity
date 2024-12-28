#pragma once
#include "window.h"

extern "C" {
	__declspec(dllexport) Window* createWindow(const char* windowName)
	{
		return new Window(windowName);
	}

	__declspec(dllexport) bool shouldClose(Window * window)
	{
		return window->shouldClose();
	}

	__declspec(dllexport) void frameCalculations(Window* window)
	{
		window->frameCalculations();
	}

	__declspec(dllexport) void clear(Window* window, Color color)
	{
		window->clear(color);
	}

	__declspec(dllexport) void draw(Window* window, Drawable* drawable)
	{
		window->draw(drawable);
	}

	__declspec(dllexport) void render(Window* window)
	{
		window->render();
	}

	__declspec(dllexport) int getKey(Window* window, int key)
	{
		return window->getKey(key);
	}

	__declspec(dllexport) vector3 getCursorPos(Window* window)
	{
		return window->getCursorPos();
	}

	__declspec(dllexport) void setMouseInputMode(Window* window, int value)
	{
		window->setMouseInputMode(value);
	}

	__declspec(dllexport) void close(Window* window)
	{
		window->close();
	}
}
#pragma once
#include "window.h"

extern "C" {
	//fields and properties
	__declspec(dllexport) Camera* Window_getCamera(Window* window)
	{
		return &window->camera;
	}

	__declspec(dllexport) float Window_getDeltaTime(Window* window)
	{
		return window->deltaTime;
	}

	__declspec(dllexport) Scene* Window_getScene(Window* window) 
	{
		return &window->scene;
	}

	//constructors
	__declspec(dllexport) Window* Window_create(const char* windowName)
	{
		return new Window(windowName);
	}

	//functions
	__declspec(dllexport) void Window_show(Window* window)
	{
		window->show();
	}

	__declspec(dllexport) void Window_setOnFrame(Window* window, OnFrameCallback cb)
	{
		window->setOnFrameCallback(cb);
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
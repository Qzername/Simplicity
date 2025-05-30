#pragma once

#define EXPORT __declspec(dllexport)

#include "window.h"

extern "C" {
	//fields and properties
	EXPORT Camera* Window_getCamera(Window* window)
	{
		return &window->camera;
	}

	EXPORT float Window_getDeltaTime(Window* window)
	{
		return window->deltaTime;
	}

	EXPORT Scene* Window_getScene(Window* window)
	{
		return &window->scene;
	}

	EXPORT Input* Window_getInput(Window* window)
	{
		return &window->input;
	}

	//constructors
	EXPORT Window* Window_create(const char* windowName)
	{
		return new Window(windowName);
	}

	//functions
	EXPORT void Window_show(Window* window)
	{
		window->show();
	}

	EXPORT void Window_setOnFrame(Window* window, OnFrameCallback cb)
	{
		window->setOnFrameCallback(cb);
	}

	EXPORT void Window_setMouseInputMode(Window* window, int value)
	{
		window->setMouseInputMode(value);
	}

	EXPORT void Window_close(Window* window)
	{
		window->close();
	}
}
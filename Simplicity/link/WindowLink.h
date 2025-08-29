#pragma once

#define EXPORT __declspec(dllexport)

#include <Window.h>

extern "C" {
	//fields and properties
	EXPORT float Window_getDeltaTime(Window* window)
	{
		return window->deltaTime;
	}

	EXPORT Input* Window_getInput(Window* window)
	{
		return &window->input;
	}

	EXPORT Graphics* Window_getGraphics(Window* window) 
	{
		return &window->graphics;
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

	EXPORT void Window_close(Window* window)
	{
		window->close();
	}
}
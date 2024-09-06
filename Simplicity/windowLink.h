#pragma once

#include "window.h"
#include "rectangle.h"

extern "C" {
	__declspec(dllexport) Window* createWindow()
	{
		return new Window("window");
	}

	__declspec(dllexport) void show(Window* window) {
		window->show();
	}

	__declspec(dllexport) void addDrawable(Window* window, Drawable* drawable)
	{
		window->addDrawable(drawable);
	}
}
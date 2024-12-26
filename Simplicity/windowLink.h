#pragma once

#include "window.h"
#include "rectangle.h"

extern "C" {
	__declspec(dllexport) Window* createWindow()
	{
		return new Window("window");
	}
}
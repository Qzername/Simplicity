#pragma once

#include "rectangle.h"

extern "C" {
	__declspec(dllexport) Rectangle* createRectangle(float x, float y, float width, float height)
	{
		return new Rectangle(x,y,width,height);
	}
}
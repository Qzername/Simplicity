#pragma once

#include "rectangle.h"

extern "C" {
	__declspec(dllexport) Rectangle* Rectangle_create(float x, float y, float width, float height)
	{
		return new Rectangle(x,y,width,height);
	}
}
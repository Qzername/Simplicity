#pragma once
#include "color.h"

extern "C" {
	__declspec(dllexport) Color* createColor(float r, float g, float b, float w)
	{
		return new Color(r,g,b,w);
	}

	__declspec(dllexport) Color* createColor(float r, float g, float b)
	{
		return new Color(r,g,b);
	}

	__declspec(dllexport) Color* createColor()
	{
		return new Color();
	}
}
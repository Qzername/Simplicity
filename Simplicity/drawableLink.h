#pragma once
#include "texture2D.h"

extern "C" {
	__declspec(dllexport) Transform* Drawable_getTransform(Drawable* drawable)
	{
		return &drawable->transform;
	}

	__declspec(dllexport) Color Drawable_getColor(Drawable* drawable)
	{
		return drawable->color;
	}

	__declspec(dllexport) void Drawable_setColor(Drawable* Drawable, Color color)
	{
		Drawable->color = color;
	}

	__declspec(dllexport) void Drawable_setTexture(Drawable* Drawable, Texture2D* texture) {
		Drawable->setTexture(texture);
	}
}
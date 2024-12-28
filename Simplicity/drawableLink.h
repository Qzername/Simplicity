#pragma once

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
}
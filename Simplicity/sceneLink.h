#pragma once
#include "scene.h"

extern "C" {
	//fields and properties
	__declspec(dllexport) Color Scene_getBackgroundColor(Scene* scene)
	{
		return scene->getBackgroundColor();
	}

	__declspec(dllexport) void Scene_setBackgroundColor(Scene* scene, Color color)
	{
		scene->setBackgroundColor(color);
	}

	//methods
	__declspec(dllexport) void Scene_instantiate(Scene* scene, Drawable* drawable)
	{
		scene->Instantiate(drawable);
	}

	__declspec(dllexport) void Scene_destroy(Scene* scene, Drawable* drawable)
	{
		scene->Destroy(drawable);
	}
}
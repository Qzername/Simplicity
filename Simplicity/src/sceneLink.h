#pragma once

#define EXPORT __declspec(dllexport)

#include "scene.h"

extern "C" {
	EXPORT Scene* Scene_create() 
	{
		return new Scene();
	}

	EXPORT void Scene_instantiate(Scene* scene, GraphicsObject* graphicsObject)
	{
		scene->Instantiate(graphicsObject);
	}

	EXPORT void Scene_destroy(Scene* scene, GraphicsObject* graphicsObject)
	{
		scene->Destroy(graphicsObject);
	}

	EXPORT void Scene_render(Scene* scene, Renderer* renderer)
	{
		scene->Render(renderer);
	}
}
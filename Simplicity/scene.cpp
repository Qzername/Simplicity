#include "scene.h"

void Scene::Render(Renderer renderer)
{
	for (auto& object : objects)
		renderer.Render(*object);
}

void Scene::Instantiate(GraphicsObject* graphicsObject)
{
	objects.push_back(graphicsObject);
}

void Scene::Destroy(GraphicsObject* graphicsObject)
{
	objects.erase(std::remove(objects.begin(), objects.end(), graphicsObject), objects.end());
}
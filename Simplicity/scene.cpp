#include "scene.h"

Scene::Scene()
{
	backgroundColor = Color(255, 255, 255);
}

Color Scene::getBackgroundColor() {
	return backgroundColor;
}

void Scene::setBackgroundColor(Color color) {
	this->backgroundColor = color;
}

void Scene::Instantiate(Drawable* shaderProgram)
{
	objects.push_back(shaderProgram);
}

void Scene::Destroy(Drawable* shaderProgram)
{
	objects.erase(std::remove(objects.begin(), objects.end(), shaderProgram), objects.end());
}
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "drawable.h"

class Rectangle : Drawable
{
	float width, height;

	unsigned int VAO; 

public:
	Rectangle(float x, float y, float width, float height);

	unsigned int GenerateVAO();

	void Render();
};
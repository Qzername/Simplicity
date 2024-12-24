#pragma once
#include <glad/glad.h>

class Texture2D {
	unsigned int texture;

public:
	Texture2D();

	void SetActive();
};
#pragma once
#include <glad/glad.h>

enum class TextureFormat
{
	SingleColor = 1,
	RGB = 3,
	RGBA = 4
};

class Texture2D {
	unsigned int texture;

	Texture2D(int width, int height, unsigned char data[], TextureFormat textureFormat);
public:
	void SetActive();

	static Texture2D LoadFromFile(const char* filename);
	static Texture2D LoadFromData(int width, int height, unsigned char data[], TextureFormat textureFormat);
};
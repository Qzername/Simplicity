#pragma once
#include <glad/glad.h>

class Texture2D {
	unsigned int texture;

	Texture2D(int width, int height, unsigned char data[]);
public:
	void SetActive();

	static Texture2D LoadFromFile(const char* filename);
	static Texture2D LoadFromData(int width, int height, unsigned char data[]);
};
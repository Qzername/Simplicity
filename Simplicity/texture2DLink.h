#pragma once

#include "texture2D.h"

extern "C" {
	__declspec(dllexport) Texture2D* Texture2D_LoadFromFile(const char* filename) {
		Texture2D texture = Texture2D::LoadFromFile(filename);

		return &texture;
	}

	__declspec(dllexport) Texture2D* Texture_LoadFromData(int width, int height, unsigned char data[]) {
		Texture2D texture = Texture2D::LoadFromData(width, height, data);
	
		return &texture;
	}
}
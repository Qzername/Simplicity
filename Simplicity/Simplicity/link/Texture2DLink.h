#pragma once

#include <Graphics/Objects/Texture2D.h>

extern "C" {
	__declspec(dllexport) Texture2D* Texture2D_LoadFromFile(const char* filename) {
		return new Texture2D(Texture2D::LoadFromFile(filename));
	}

	__declspec(dllexport) Texture2D* Texture_LoadFromData(int width, int height, unsigned char data[], TextureFormat textureFormat) {
		return new Texture2D(Texture2D::LoadFromData(width, height, data, textureFormat));
	}
}
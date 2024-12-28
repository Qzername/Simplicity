#pragma once

#include "texture2D.h"

extern "C" {
	__declspec(dllexport) Texture2D* Texture2D_create(const char* filename) {
		return new Texture2D(filename);
	}

	__declspec(dllexport) void Texture2D_setActive(Texture2D* texture) {
		texture->SetActive();
	}
}
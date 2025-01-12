#pragma once

#include "model.h"

extern "C" {
	__declspec(dllexport) Model* Model_create(const char* filename)
	{
		return new Model(filename);
	}
}
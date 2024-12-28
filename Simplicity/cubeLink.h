#pragma once

#include "cube.h"

extern "C" {
	__declspec(dllexport) Cube* Cube_create(vector3 position)
	{
		return new Cube(position);
	}
}
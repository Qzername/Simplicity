#pragma once

#define EXPORT __declspec(dllexport)

#include "Geometries.h"

extern "C" {
	EXPORT Geometry* Geometries_cube() {
		return Geometries::cube();
	}

	EXPORT Geometry* Geometries_rectangle(float width, float height) {
		return Geometries::rectangle(width, height);
	}

	EXPORT Geometry* Geometries_wheel(unsigned int segments, float radius) {
		return Geometries::wheel(segments, radius);
	}

	EXPORT Geometry* Geometries_loadModel(const char* path) {
		return Geometries::loadModel(path);
	}
}
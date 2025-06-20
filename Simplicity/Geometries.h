#pragma once

#include "geometry.h"

namespace Geometries {
	Geometry* cube();
	Geometry* rectangle(float width, float height);
	Geometry* loadModel(string const& path);
	Geometry* wheel(unsigned int segments, float radius);
}
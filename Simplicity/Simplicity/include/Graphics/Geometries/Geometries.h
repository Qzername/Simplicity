#pragma once

#include <Graphics/Objects/Geometry.h>
#include <string>

namespace Geometries {
	Geometry* cube();
	Geometry* rectangle(float width, float height);
	Geometry* loadModel(string const& path);
	Geometry* wheel(unsigned int segments, float radius);
}
#pragma once

#include "coreDefinitions.h"

#include <Graphics/Objects/Geometry.h>
#include <string>

namespace Geometries {
	CPP_LIB_EXP Geometry* cube();
	CPP_LIB_EXP Geometry* rectangle(float width, float height);
	CPP_LIB_EXP Geometry* loadModel(string const& path);
	CPP_LIB_EXP Geometry* wheel(unsigned int segments, float radius);
}
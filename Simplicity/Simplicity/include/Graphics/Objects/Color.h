#pragma once

#include "coreDefinitions.h"

struct CPP_LIB_EXP Color {
	float r, g, b, w;

	Color(float r, float g, float b);
	Color();
	Color(float r, float g, float b, float w);
};
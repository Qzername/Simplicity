#pragma once

#include "vector3.h"
#include "vector2.h"

struct Vertex {
    vector3 position;
    vector3 normal { 0.0f, 0.0f, 0.0f };
    vector2 texCoords { 0.0f, 0.0f };
};
#pragma once

#include <Vector3.h>
#include <Vector2.h>

struct Vertex {
    Vector3 position;
    Vector3 normal { 0.0f, 0.0f, 0.0f };
    Vector2 texCoords { 0.0f, 0.0f };
};
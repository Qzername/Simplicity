#include "Geometries.h"

namespace Geometries {
    Geometry* rectangle(float width, float height) {
        std::vector<Vertex> vertices = {
            {{0.0f,  0.0f,   0.0f}, {}, {0.0f, 0.0f}},
            {{width, 0.0f,   0.0f}, {}, {1.0f, 0.0f}},
            {{width, height, 0.0f}, {}, {1.0f, 1.0f}},
            {{0.0f,  height, 0.0f}, {}, {0.0f, 1.0f}}
        };

        std::vector<unsigned int> indices = {
            0, 1, 3,
            1, 2, 3
        };

        Mesh mesh(vertices, indices);
        
        Geometry geometry;
        geometry.meshes.push_back(mesh);

        return new Geometry(geometry);
    }
}
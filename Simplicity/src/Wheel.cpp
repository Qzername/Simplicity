#define _USE_MATH_DEFINES

#include "Geometries.h"
#include <math.h>

namespace Geometries {
	Geometry* wheel(unsigned int segments, float radius) {
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;

        Vertex centerVertex;
        centerVertex.position = vector3(0.0f, 0.0f, 0.0f);
        centerVertex.texCoords = vector2(0.5f, 0.5f); 
        vertices.push_back(centerVertex);

        for (int i = 0; i < segments; ++i) {
            float angle = 2.0f * M_PI * i / segments;
            float x = radius * cos(angle);
            float y = radius * sin(angle);

            Vertex outerVertex;
            outerVertex.position = vector3(x, y, 0.0f);

            outerVertex.texCoords = vector2(0.5f + 0.5f * cos(angle), 0.5f + 0.5f * sin(angle));

            vertices.push_back(outerVertex);
        }

        for (int i = 0; i < segments; ++i) {
            int current = i + 1;
            int next = (i + 1) % segments + 1;
            indices.push_back(0);       
            indices.push_back(current); 
            indices.push_back(next);    
        }

        Mesh mesh(vertices, indices);

        Geometry geometry;
        geometry.meshes.push_back(mesh);

        return new Geometry(geometry);
	}
}
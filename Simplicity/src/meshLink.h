#pragma once

#define EXPORT __declspec(dllexport)

#include "mesh.h"

extern "C" {
	EXPORT Mesh* Mesh_create(Vertex* vertices, int vertexCount, unsigned int* indices, int indexCount) {
		vector<Vertex> verticesVec;
		verticesVec.assign(vertices, vertices + vertexCount);

		vector<unsigned int> indicesVec;
		indicesVec.assign(indices, indices + indexCount);

		return new Mesh(verticesVec, indicesVec);
	}
}
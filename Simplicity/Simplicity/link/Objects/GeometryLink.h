#pragma once

#define EXPORT __declspec(dllexport)

#include <Graphics/Objects/Geometry.h>

EXPORT Geometry* Geometry_create(Mesh* mesh, int meshCount) {
	vector<Mesh> meshes;
	meshes.assign(mesh, mesh + meshCount);

	Geometry geometry;
	geometry.meshes = meshes;

	return new Geometry(geometry);
}
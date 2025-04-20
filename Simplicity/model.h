#pragma once

#include <glad/glad.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <stb_image/stb_image.h>

#include <string>
#include <vector>
#include <map>

#include "mesh.h"
#include "vector3.h"
#include "drawable.h"

using namespace std;

class Model : public Drawable
{
public:
    vector<Mesh> meshes;
    string directory;

    Model(string const& path);
    void render(unsigned int shaderProgram);

private:
    void processNode(aiNode* node, const aiScene* scene);
    Mesh processMesh(aiMesh* mesh, const aiScene* scene);
};
#include "texture2D.h"
#include <stb_image/stb_image.h>
#include <iostream>

using namespace std;

void generateTextureWithData(unsigned int* texture, int width, int height, unsigned char* data);

Texture2D::Texture2D(int width, int height, unsigned char data[]) {
    generateTextureWithData(&texture, width, height, data);
}

void Texture2D::SetActive()
{
    glBindTexture(GL_TEXTURE_2D, this->texture);
}

Texture2D Texture2D::LoadFromFile(const char* filename)
{
    int width, height, nrChannels;
    unsigned char* data = stbi_load(filename, &width, &height, &nrChannels, 0);

    Texture2D texture = Texture2D(width, height, data);
    stbi_image_free(data);

    return texture;
}

Texture2D Texture2D::LoadFromData(int width, int height, unsigned char data[]) {
    return Texture2D(width, height, data);
}

void generateTextureWithData(unsigned int* texture, int width, int height, unsigned char* data)
{
    glGenTextures(1, texture);
    glBindTexture(GL_TEXTURE_2D, *texture);

    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
}
#include "CubeMap.h"

#include <iostream>
using namespace std;

namespace CGE
{
    CubeMap::CubeMap() : Texture(GL_TEXTURE_CUBE_MAP)
    {
    }

    CubeMap::~CubeMap()
    {
    }

    void CubeMap::loadImages(const Image* inImages[])
    {
        const GLenum faces[6] = {
            GL_TEXTURE_CUBE_MAP_POSITIVE_X,
            GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
            GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
            GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
            GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
            GL_TEXTURE_CUBE_MAP_NEGATIVE_Z };

        const GLenum params1[] = {
            GL_TEXTURE_MAG_FILTER, GL_LINEAR,
            GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE,
            GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE,
            GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE,
            0 };

        const GLenum params2[] = {
            GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR,
            0 };

        bind();
        processParams(params1);

        for (size_t i = 0; i < 6; ++i)
            inImages[i]->loadIntoTexture(faces[i]);

        glGenerateMipmap(mTarget);
        processParams(params2);
    }

    void CubeMap::loadFiles(const char* inFiles[])
    {
        Image images[6];
        const Image* imagePointers[6];
        for (size_t i = 0; i < 6; ++i)
        {
            images[i].loadFile(inFiles[i]);
            imagePointers[i] = images + i;
        }

        loadImages(imagePointers);
    }
}

#include "Texture.h"

namespace CGE
{
    Texture::Texture(GLenum inTarget) : mTarget(inTarget)
    {
        glGenTextures(1, &mHandle);
    }

    Texture::~Texture()
    {
        if (mHandle) glDeleteTextures(1, &mHandle);
    }

    void Texture::processParams(const GLenum inParams[])
    {
        for (const GLenum *i = inParams; *i; i += 2)
            glTexParameteri(mTarget, i[0], i[1]);
    }
}

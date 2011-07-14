#ifndef CGE_OPENGL_H
#define CGE_OPENGL_H

#include <GLee/GLee.h>
typedef GLint GLuniform;

#include <SDL.h>
typedef SDL_Surface* Surface;
typedef SDL_Joystick* Joystick;

#include "Matrix4x4.h"
#include "Vectors.h"

namespace CGE
{
    void transform(const Matrix4x4<GLfloat>& inMatrix, const GLfloat* inVector,
        GLfloat* inResult);

    bool unproject(GLfloat inX, GLfloat inY, GLfloat inZ,
        const Matrix4x4<GLfloat>& inModelViewProjection,
        const GLint* inViewport, GLfloat* inResult);
}

#endif

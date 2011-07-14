#include "Graphics.h"

namespace CGE
{
    void transform(const Matrix4x4<GLfloat>& inMatrix, const GLfloat* inVector,
        GLfloat* inResult)
    {
        inResult[0] = inMatrix(0, 0) * inVector[0] + inMatrix(0, 1)
            * inVector[1] + inMatrix(0, 2) * inVector[2] + inMatrix(0, 3)
            * inVector[3];

        inResult[1] = inMatrix(1, 0) * inVector[0] + inMatrix(1, 1)
            * inVector[1] + inMatrix(1, 2) * inVector[2] + inMatrix(1, 3)
            * inVector[3];

        inResult[2] = inMatrix(2, 0) * inVector[0] + inMatrix(2, 1)
            * inVector[1] + inMatrix(2, 2) * inVector[2] + inMatrix(2, 3)
            * inVector[3];

        inResult[3] = inMatrix(3, 0) * inVector[0] + inMatrix(3, 1)
            * inVector[1] + inMatrix(3, 2) * inVector[2] + inMatrix(3, 3)
            * inVector[3];
    }

    bool unproject(GLfloat inX, GLfloat inY, GLfloat inZ,
        const Matrix4x4<GLfloat>& inModelViewProjection,
        const GLint* inViewport, GLfloat* inResult)
    {
        float in[4];

        in[0] = (inX - inViewport[0]) * 2.0f / inViewport[2] - 1.0f;
        in[1] = (inY - inViewport[1]) * 2.0f / inViewport[3] - 1.0f;
        in[2] = 2.0f * inZ - 1.0f;
        in[3] = 1.0f;

        Matrix4x4<GLfloat> m;
        inModelViewProjection.copyInverseTo(m);
        transform(m, in, inResult);
        if (inResult[3] == 0.0f) return false;
        inResult[0] /= inResult[3];
        inResult[1] /= inResult[3];
        inResult[2] /= inResult[3];
        inResult[3] = 1.0f;
        return true;
    }
}

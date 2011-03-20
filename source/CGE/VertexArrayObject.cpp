#include "VertexArrayObject.h"

namespace CGE
{
    VertexArrayObject::VertexArrayObject()
    {
        glGenVertexArrays(1, &mHandle);
    }

    VertexArrayObject::~VertexArrayObject()
    {
        glDeleteVertexArrays(1, &mHandle);
    }

    void VertexArrayObject::mount(const VertexBufferObject& inVBO,
        GLuint inIndex)
    {
        inVBO.bind();
        glEnableVertexAttribArray(inIndex);
        glVertexAttribPointer(inIndex, inVBO.mValuesPerUnit, inVBO.mType,
            GL_FALSE, 0, 0);
    }

    void VertexArrayObject::mount(const VertexBufferObject& inVBO)
    {
        inVBO.bind();
    }
}

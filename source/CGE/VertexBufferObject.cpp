#include "VertexBufferObject.h"

namespace CGE
{
    VertexBufferObject::VertexBufferObject(GLenum inTarget, GLenum inType,
        GLenum inUsage) : mTarget(inTarget), mType(inType), mUsage(inUsage),
        mValuesPerUnit(1), mSize(0)
    {
        glGenBuffers(1, &mHandle);

        switch (mType)
        {
            case GL_FLOAT:          mTypeSize = sizeof(GLfloat);  break;
            case GL_UNSIGNED_BYTE:  mTypeSize = sizeof(GLubyte);  break;
            case GL_UNSIGNED_SHORT: mTypeSize = sizeof(GLushort); break;
            case GL_UNSIGNED_INT:   mTypeSize = sizeof(GLuint);   break;

            default: {}
        }
    }

    VertexBufferObject::~VertexBufferObject()
    {
        glDeleteBuffers(1, &mHandle);
    }

    void VertexBufferObject::loadData(const GLvoid* inData, GLuint inSize,
        GLuint inValuesPerUnit)
    {
        bind();
        mSize = inSize;
        mValuesPerUnit = inValuesPerUnit;
        glBufferData(mTarget, mSize * mValuesPerUnit * mTypeSize, inData,
            mUsage);
    }

    void VertexBufferObject::vertexAttribPointer(GLuint inIndex) const
    {
        bind();
        glVertexAttribPointer(inIndex, mValuesPerUnit, mType, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(inIndex);
    }
}

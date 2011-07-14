#include "VertexBufferObject.h"
#include <cassert>

namespace CGE
{
    VertexBufferObject::VertexBufferObject(GLenum inTarget, GLenum inType,
        GLenum inUsage) : mIndex(0), mTarget(inTarget), mType(inType),
        mUsage(inUsage), mValuesPerUnit(1), mSize(0)
    {
        glGenBuffers(1, &mHandle);

        switch (mType)
        {
            case GL_FLOAT:          mTypeSize = sizeof(GLfloat);  break;
            case GL_UNSIGNED_BYTE:  mTypeSize = sizeof(GLubyte);  break;
            case GL_UNSIGNED_SHORT: mTypeSize = sizeof(GLushort); break;
            case GL_UNSIGNED_INT:   mTypeSize = sizeof(GLuint);   break;

            default:
                mType = GL_FLOAT;
                mTypeSize = sizeof(GLfloat);
        }
    }

    VertexBufferObject::~VertexBufferObject()
    {
        glDeleteBuffers(1, &mHandle);
    }

    void VertexBufferObject::loadData(const GLvoid* inData, GLuint inSize,
        GLuint inValuesPerUnit)
    {
        assert(inData != NULL);
        assert(inSize > 0);
        assert(inValuesPerUnit > 0);

        bind();
        mSize = inSize;
        mValuesPerUnit = inValuesPerUnit;
        glBufferData(mTarget, mSize * mValuesPerUnit * mTypeSize, inData,
            mUsage);
    }

    // enableVAA == enable vertex attrib array
    void VertexBufferObject::enableVAA(GLuint inIndex)
    {
        mIndex = inIndex;
        enableVAA();
    }

    void VertexBufferObject::enableVAA()
    {
        bind();
        glVertexAttribPointer(mIndex, mValuesPerUnit, mType, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(mIndex);
    }

    // disableVAA == disable vertex attrib array
    void VertexBufferObject::disableVAA()
    {
        glDisableVertexAttribArray(mIndex);
    }
}

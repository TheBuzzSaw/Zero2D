#ifndef VERTEXBUFFEROBJECT_H
#define VERTEXBUFFEROBJECT_H

#include "Graphics.h"

namespace CGE
{
    class VertexBufferObject
    {
        public:
            friend class VertexArrayObject;

            VertexBufferObject(GLenum inTarget = GL_ARRAY_BUFFER,
                GLenum inType = GL_FLOAT, GLenum inUsage = GL_STATIC_DRAW);
            virtual ~VertexBufferObject();

            inline void bind() const { glBindBuffer(mTarget, mHandle); }
            inline bool isBuffer() const
            {
                return glIsBuffer(mHandle) == GL_TRUE;
            }

            void loadData(const GLvoid* inData, GLuint inSize,
                GLuint inValuesPerUnit = 1);
            void enableVAA(GLuint inIndex);
            void enableVAA();
            void disableVAA();

        protected:
            GLuint mHandle;
            GLuint mIndex;
            GLenum mTarget;
            GLenum mType;
            GLenum mUsage;
            GLuint mTypeSize;
            GLuint mValuesPerUnit;
            GLuint mSize;
    };
}

#endif

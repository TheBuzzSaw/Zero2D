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
            void loadData(const GLvoid* inData, GLuint inSize,
                GLuint inValuesPerUnit = 1);
            void vertexAttribPointer(GLuint inIndex) const;

        protected:
            GLuint mHandle;
            GLenum mTarget;
            GLenum mType;
            GLenum mUsage;
            GLuint mTypeSize;
            GLuint mValuesPerUnit;
            GLuint mSize;
    };
}

#endif

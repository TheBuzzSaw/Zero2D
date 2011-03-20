#ifndef VERTEXARRAYOBJECT_H
#define VERTEXARRAYOBJECT_H

#include "VertexBufferObject.h"

namespace CGE
{
    class VertexArrayObject
    {
        public:
            VertexArrayObject();
            ~VertexArrayObject();

            inline void bind() const { glBindVertexArray(mHandle); }
            void mount(const VertexBufferObject& inVBO, GLuint inIndex);
            void mount(const VertexBufferObject& inVBO);

            static inline void unbind() { glBindVertexArray(0); }

        private:
            GLuint mHandle;
    };
}

#endif

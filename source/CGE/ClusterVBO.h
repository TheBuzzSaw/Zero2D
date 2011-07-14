#ifndef CLUSTERVBO_H
#define CLUSTERVBO_H

#include "IndexVBO.h"

namespace CGE
{
    class ClusterVBO
    {
        public:
            ClusterVBO(size_t inSize);
            ~ClusterVBO();

            void mount(const IndexVBO& inIVBO);
            void mount(VertexBufferObject& inVBO, size_t inIndex);
            void display(GLenum inMode = GL_TRIANGLES);
            void display(const IndexVBO& inIVBO, GLenum inMode = GL_TRIANGLES);

        private:
            size_t mSize;
            VertexBufferObject** mBuffers;
            const IndexVBO* mIVBO;
    };
}

#endif

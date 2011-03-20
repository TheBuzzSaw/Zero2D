#ifndef INDEXVBO_H
#define INDEXVBO_H

#include "VertexBufferObject.h"

namespace CGE
{
    class IndexVBO : public VertexBufferObject
    {
        public:
            IndexVBO(GLenum inUsage = GL_STATIC_DRAW);
            virtual ~IndexVBO();

            void draw(GLenum inMode = GL_TRIANGLES) const;

        protected:
        private:
    };
}

#endif

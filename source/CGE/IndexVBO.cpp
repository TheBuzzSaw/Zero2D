#include "IndexVBO.h"

namespace CGE
{
    IndexVBO::IndexVBO(GLenum inUsage)
        : VertexBufferObject(GL_ELEMENT_ARRAY_BUFFER, GL_UNSIGNED_INT,
        inUsage)
    {
    }

    IndexVBO::~IndexVBO()
    {
    }

    void IndexVBO::draw(GLenum inMode) const
    {
        bind();
        glDrawElements(inMode, mSize * mValuesPerUnit, mType, 0);
    }

}

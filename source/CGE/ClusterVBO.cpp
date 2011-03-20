#include "ClusterVBO.h"

namespace CGE
{
    ClusterVBO::ClusterVBO(size_t inSize) : mSize(inSize)
    {
        if (!mSize) mSize = 1;
        mBuffers = new const VertexBufferObject*[mSize];
    }

    ClusterVBO::~ClusterVBO()
    {
        delete [] mBuffers;
    }

    void ClusterVBO::mount(const VertexBufferObject& inVBO, size_t inIndex)
    {
        if (inIndex >= mSize) return;

        mBuffers[inIndex] = &inVBO;
    }

    void ClusterVBO::display(const IndexVBO& inIVBO, GLenum inMode)
    {
        for (size_t i = 0; i < mSize; ++i)
            mBuffers[i]->vertexAttribPointer(i);

        inIVBO.draw(inMode);

        for (size_t i = 0; i < mSize; ++i)
            glDisableVertexAttribArray(i);
    }
}

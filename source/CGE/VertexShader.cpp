#include "VertexShader.h"

namespace CGE
{
    VertexShader::VertexShader() : Shader(GL_VERTEX_SHADER)
    {
    }

    VertexShader::VertexShader(const char* inFile) : Shader(GL_VERTEX_SHADER)
    {
        loadFromFile(inFile);
    }

    VertexShader::~VertexShader()
    {
    }

}

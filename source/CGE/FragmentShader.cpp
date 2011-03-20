#include "FragmentShader.h"

namespace CGE
{
    FragmentShader::FragmentShader() : Shader(GL_FRAGMENT_SHADER)
    {
    }

    FragmentShader::FragmentShader(const char* inFile)
        : Shader(GL_FRAGMENT_SHADER)
    {
        loadFromFile(inFile);
    }

    FragmentShader::~FragmentShader()
    {
    }
}

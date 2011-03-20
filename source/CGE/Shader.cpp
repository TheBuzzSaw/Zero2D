#include "Shader.h"
#include "Exception.h"

#include "Tools.h"

namespace CGE
{
    const char* Shader::mFile = "(direct buffer)";

    Shader::Shader(GLenum inType) : mHandle(0)
    {
        mHandle = glCreateShader(inType);
    }

    Shader::~Shader()
    {
        if (mHandle) glDeleteShader(mHandle);
    }

    void Shader::loadFromFile(const char* inFile)
    {
        static const char* functionName = "Shader::loadFromFile";

        if (!inFile || !*inFile) return;

        char* source = fileToBuffer(inFile);
        if (!source)
        {
            std::string message("failed to convert ");
            message += inFile;
            message += " to buffer";
            throw Exception(functionName, message);
        }

        const char* temp = mFile;
        mFile = inFile;
        loadFromBuffer(source);
        mFile = temp;

        delete [] source;
    }

    void Shader::loadFromBuffer(const char* inBuffer)
    {
        static const char* functionName = "Shader::loadFromBuffer";

        glShaderSource(mHandle, 1, const_cast<const GLchar**>(&inBuffer), 0);
        glCompileShader(mHandle);

        GLint compiled;
        glGetShaderiv(mHandle, GL_COMPILE_STATUS, &compiled);
        if (!compiled)
        {
            GLchar log[2048];
            GLsizei length;
            glGetShaderInfoLog(mHandle, 2048, &length, log);

            std::string message("shader compiler errors -- ");
            message += mFile;
            message += '\n';
            message += log;

            throw Exception(functionName, message);
        }
    }
}

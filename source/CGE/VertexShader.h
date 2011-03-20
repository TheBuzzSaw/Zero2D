#ifndef VERTEXSHADER_H
#define VERTEXSHADER_H

#include "Shader.h"

namespace CGE
{
    class VertexShader : public Shader
    {
        public:
            VertexShader();
            VertexShader(const char* inFile);
            virtual ~VertexShader();

        private:
            VertexShader(const VertexShader& inShader) : Shader(0)
            {
                // no copying
            }

            VertexShader& operator=(const VertexShader& inShader)
            {
                // no copying
                return *this;
            }
    };
}

#endif

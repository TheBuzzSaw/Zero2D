#ifndef FRAGMENTSHADER_H
#define FRAGMENTSHADER_H

#include "Shader.h"

namespace CGE
{
    class FragmentShader : public Shader
    {
        public:
            FragmentShader();
            FragmentShader(const char* inFile);
            virtual ~FragmentShader();

        private:
            FragmentShader(const FragmentShader& inShader) : Shader(0)
            {
                // no copying
            }

            FragmentShader& operator=(const FragmentShader& inShader)
            {
                // no copying
                return *this;
            }
    };
}

#endif

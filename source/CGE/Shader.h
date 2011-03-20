#ifndef SHADER_H
#define SHADER_H

#include "Graphics.h"

namespace CGE
{
    class Shader
    {
        public:
            Shader(GLenum inType);
            virtual ~Shader();

            inline GLuint handle() const { return mHandle; }
            void loadFromFile(const char* inFile);
            void loadFromBuffer(const char* inBuffer);

        private:
            Shader(const Shader& inShader)
            {
                // no copying
            }

            Shader& operator=(const Shader& inShader)
            {
                // no copying
                return *this;
            }

            GLuint mHandle;

            static const char* mFile;
    };
}

#endif

#ifndef PROGRAM_H
#define PROGRAM_H

#include "Shader.h"

namespace CGE
{
    template<size_t N>
    class Program
    {
        public:
            Program();
            virtual ~Program();

            void attachShader(const Shader& inShader);
            void attachShader(GLuint inShader);
            void bindAttribLocation(GLuint inIndex, const GLchar* inName);
            void link();
            GLint getUniformLocation(const GLchar* inName);
            void clear();

            inline void use() const { glUseProgram(mHandle); }

        private:
            GLuint mHandle;
            GLuint mShaders[N];
            size_t mSize;
            bool mLinked;
    };

    template<size_t N>
    Program<N>::Program() : mHandle(0), mSize(0), mLinked(false)
    {
    }

    template<size_t N>
    Program<N>::~Program()
    {
        clear();
    }

    template<size_t N>
    void Program<N>::attachShader(const Shader& inShader)
    {
        attachShader(inShader.handle());
    }

    template<size_t N>
    void Program<N>::attachShader(GLuint inShader)
    {
        if (mLinked)
        {
            // More shaders cannot be attached if the program is already linked.
            return;
        }

        if (mSize >= N)
        {
            return;
        }

        if (!mSize)
        {
            // If the shader container is empty, we have not yet created the
            // shader program. That needs to be done first!

            mHandle = glCreateProgram();
            if (!mHandle)
            {
                // TODO: report error through XPG exception
                return;
            }
        }

        mShaders[mSize] = inShader;
        ++mSize;

        glAttachShader(mHandle, inShader);
    }

    template<size_t N>
    void Program<N>::bindAttribLocation(GLuint inIndex, const GLchar* inName)
    {
        glBindAttribLocation(mHandle, inIndex, inName);
    }

    template<size_t N>
    void Program<N>::link()
    {
        if (mLinked)
        {
            // TODO: report error through XPG exception
            return;
        }

        if (mSize < 2 || !mHandle)
        {
            // TODO: report error through XPG exception
            return;
        }

        glLinkProgram(mHandle);

        GLint linked;
        glGetProgramiv(mHandle, GL_LINK_STATUS, &linked);

        if (!linked)
        {
            // TODO: report error through XPG exception
            return;
        }

        mLinked = true;
        use();
    }

    template<size_t N>
    GLint Program<N>::getUniformLocation(const GLchar* inName)
    {
        return glGetUniformLocation(mHandle, inName);
    }

    template<size_t N>
    void Program<N>::clear()
    {
        for (size_t i = 0; i < mSize; ++i)
            glDetachShader(mHandle, mShaders[i]);

        mSize = 0;
        mLinked = false;

        if (mHandle)
        {
            glDeleteProgram(mHandle);
            mHandle = 0;
        }
    }
}

#endif

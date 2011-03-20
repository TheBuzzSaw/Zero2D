#ifndef TEXTURE_H
#define TEXTURE_H

#include "Graphics.h"

namespace CGE
{
    class Texture
    {
        public:
            Texture(GLenum inTarget);
            virtual ~Texture();

            inline void bind() const { glBindTexture(mTarget, mHandle); }

        protected:
            void processParams(const GLenum inParams[]);

            GLenum mTarget;

        private:
            Texture(const Texture& inTexture)
            {
                // no copying
            }

            Texture& operator=(const Texture& inTexture)
            {
                // no copying
                return *this;
            }

            GLuint mHandle;

    };
}

#endif

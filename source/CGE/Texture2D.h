#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include "Texture.h"
#include "Image.h"

namespace CGE
{
    class Texture2D : public Texture
    {
        public:
            Texture2D();
            Texture2D(const Image& inImage);
            virtual ~Texture2D();

            void loadImage(const Image& inImage);

        private:
            Texture2D(const Texture2D& inTexture) : Texture(0)
            {
                // no copying
            }

            Texture2D& operator=(const Texture2D& inTexture)
            {
                // no copying
                return *this;
            }
    };
}

#endif

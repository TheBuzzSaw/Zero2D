#ifndef IMAGE_H
#define IMAGE_H

#include "Graphics.h"
#include "Font.h"

namespace CGE
{
    class Image
    {
        public:
            Image();
            Image(const char* inFile);
            Image(int inWidth, int inHeight);
            Image(const Image& inImage);
            ~Image();

            inline bool isValid() { return !!mData; }
            void loadFile(const char* inFile);
            void loadText(const Font& inFont, const char* inText);

            void blitOnto(Image& inImage) const;
            void loadIntoTexture(GLenum inTarget = GL_TEXTURE_2D) const;
            void setAsWindowIcon() const;
            int width() const;
            int height() const;

        private:
            void destroy();
            void findFormat();

            Surface mData;
            int mColors;
            GLenum mFormat;
    };
}

#endif

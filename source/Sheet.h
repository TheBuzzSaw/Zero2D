#ifndef SHEET_H
#define SHEET_H

#include <CGE/OpenGL/Texture2D.h>

class Sheet
{
    public:
        Sheet(const char* inPath);
        virtual ~Sheet();

        void display(int inX, int inY, int inW, int inH);

    protected:
    private:
        CGE::Texture2D mTexture;
        int mWidth;
        int mHeight;
};

#endif

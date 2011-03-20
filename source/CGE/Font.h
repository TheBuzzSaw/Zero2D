#ifndef FONT_H
#define FONT_H

#include <SDL_ttf.h>

namespace CGE
{
    class Font
    {
        public:
            Font(const char* inFile, int inSize);
            ~Font();

            friend class Image;

        private:
            TTF_Font* mFont;
    };
}

#endif

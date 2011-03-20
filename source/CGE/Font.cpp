#include "Font.h"
#include "Exception.h"

namespace CGE
{
    Font::Font(const char* inFile, int inSize)
    {
        mFont = TTF_OpenFont(inFile, inSize);

        if (!mFont)
            throw Exception("Font object", "failed to load font");
    }

    Font::~Font()
    {
        TTF_CloseFont(mFont);
    }
}

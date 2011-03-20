#include "Tools.h"

#include <cstdlib>
#include <cstdio>

namespace CGE
{
    char* fileToBuffer(const char* inFile)
    {
        FILE *f;

        if (!(f = fopen(inFile, "r"))) return NULL;

        fseek(f, 0, SEEK_END);
        size_t length = ftell(f);

        fseek(f, 0, SEEK_SET);

        char* outBuffer = static_cast<char*>(calloc(length + 1, sizeof(char)));

        if (!outBuffer) return NULL;

        size_t r = fread(outBuffer, sizeof(char), length, f);

        if (!r)
        {
            free(outBuffer);
            return NULL;
        }

        outBuffer[length] = '\0';
        fclose(f);

        return outBuffer;
    }
}

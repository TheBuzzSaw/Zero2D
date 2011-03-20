#ifndef SPRITEMETA_H
#define SPRITEMETA_H

#include <CGE/Texture2D.h>
#include <vector>
#include <sstream>

class SpriteMeta
{
    public:
        struct Region
        {
            CGE::Texture2D* texture;
            unsigned short x;
            unsigned short y;
            unsigned short width;
            unsigned short height;
        };

        struct Frame
        {
            size_t index;
            unsigned short duration;
        };

        struct Animation
        {
            Frame* frames;
            size_t count;
        };

        SpriteMeta(const char* inPath);
        ~SpriteMeta();

        Animation getAnimation(size_t inIndex) const;

    private:
        std::vector<Region> mRegions;
        std::vector<Animation> mAnimations;

        template<typename T>
        void extractNumber(const std::string& inString, T& inNumber)
        {
            std::stringstream ss(inString);
            ss >> inNumber;
        }
};

#endif

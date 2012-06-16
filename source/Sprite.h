#ifndef SPRITE_H
#define SPRITE_H

#include <map>
#include <string>
#include <iostream>

class Sprite
{
    public:
        struct Region
        {
            int x;
            int y;
            int w;
            int h;
        };

        struct Frame
        {
            const Region* region;
            int duration;
            Frame* nextFrame;
        };

        struct Animation
        {
            Frame* firstFrame;
        };

        Sprite(const char* inPath);
        virtual ~Sprite();
    protected:
    private:
        std::map<std::string, Region> mRegions;
        std::map<std::string, Animation> mAnimations;
};

std::ostream& operator<<(std::ostream& inStream,
    const Sprite::Region& inRegion);

#endif

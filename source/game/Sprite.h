#ifndef SPRITE_H
#define SPRITE_H

#include "SpriteMeta.h"

class Sprite
{
    public:
        Sprite(const SpriteMeta& inMeta);
        ~Sprite();

        void update();

    private:
        const SpriteMeta* mMeta;

        SpriteMeta::Animation mAnimation;
        SpriteMeta::Frame mFrame;
        size_t mTicks;
};

#endif

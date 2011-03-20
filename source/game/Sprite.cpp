#include "Sprite.h"

Sprite::Sprite(const SpriteMeta& inMeta) : mMeta(&inMeta), mTicks(0)
{
    mAnimation = inMeta.getAnimation(0);
}

Sprite::~Sprite()
{
}

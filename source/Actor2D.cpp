#include "Actor2D.h"
#include "RenderBin2D.h"

Actor2D::Actor2D() : mRenderBin(NULL), mNextActor(NULL), mPreviousActor(NULL)
{
}

Actor2D::~Actor2D()
{
    removeFromBin();
}

void Actor2D::removeFromBin()
{
    if (mRenderBin)
    {
        if (mRenderBin->mFirstActor == this)
            mRenderBin->mFirstActor = mNextActor;

        if (mPreviousActor) mPreviousActor->mNextActor = mNextActor;
        if (mNextActor) mNextActor->mPreviousActor = mPreviousActor;

        mPreviousActor = NULL;
        mNextActor = NULL;
        mRenderBin = NULL;
    }
}

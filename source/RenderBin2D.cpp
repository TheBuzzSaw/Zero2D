#include "RenderBin2D.h"
#include "Actor2D.h"
#include <cassert>
#include <cstdlib>

RenderBin2D::RenderBin2D() : mFirstActor(NULL)
{
}

RenderBin2D::~RenderBin2D()
{
    while (mFirstActor) mFirstActor->removeFromBin();
}

void RenderBin2D::addActor(Actor2D* inActor)
{
    assert(inActor != NULL);
    inActor->removeFromBin();
    inActor->mRenderBin = this;

    if (mFirstActor)
        mFirstActor->mPreviousActor = inActor;

    inActor->mNextActor = mFirstActor;
    mFirstActor = inActor;
}

void RenderBin2D::renderAll()
{
    if (mFirstActor)
    {
        willRender();

        for (Actor2D* a = mFirstActor; a; a = a->mNextActor) render(a);

        didRender();
    }
}

void RenderBin2D::willRender()
{
}

void RenderBin2D::didRender()
{
}

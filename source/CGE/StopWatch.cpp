#include "StopWatch.h"

namespace CGE
{
    StopWatch::StopWatch() : mTotal(0), mCurrent(0)
    {
    }

    StopWatch::~StopWatch()
    {
    }

    Uint32 StopWatch::read()
    {
        update();
        return mTotal;
    }

    void StopWatch::start()
    {
        if (!mCurrent) mCurrent = SDL_GetTicks();
    }

    void StopWatch::stop()
    {
        update();
        mCurrent = 0;
    }

    void StopWatch::reset()
    {
        mTotal = 0;
        if (mCurrent) mCurrent = SDL_GetTicks();
    }

    void StopWatch::update()
    {
        if (mCurrent)
        {
            Uint32 ticks = SDL_GetTicks();
            mTotal += ticks - mCurrent;
            mCurrent = ticks;
        }
    }

}

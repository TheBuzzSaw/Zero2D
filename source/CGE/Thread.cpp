#include "Thread.h"

namespace CGE
{
    Thread::Thread() : mRunning(false), mStop(false), mThread(NULL)
    {
    }

    Thread::~Thread()
    {
    }

    void Thread::start(Uint32 inDelay)
    {
        if (mRunning) return;
        mThread = SDL_CreateThread(startThread, this);
        SDL_Delay(inDelay);
    }

    /**
    *  Waits for a thread to finish its run() function. WARNING: Needs to be
    *  called on a thread that will end eventually without any kind of stop()
    *  call (or where you have called it prior).
    */
    void Thread::wait()
    {
        if (mRunning) SDL_WaitThread(mThread, NULL);
    }

    /**
    *  Both requests a stop in the thread and waits until the thread is no
    *  longer running. This is just an alternative to having to call stop()
    *  and wait() separately.
    */
    void Thread::stopAndWait()
    {
        stop();
        wait();
    }

    int Thread::startThread(void* inData)
    {
        Thread* t = (Thread*)inData;
        t->mStop = false;
        t->mRunning = true;
        t->run();
        t->mRunning = false;
        return 0;
    }
}

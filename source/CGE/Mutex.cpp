#include "Mutex.h"

namespace CGE
{
    Mutex::Mutex()
    {
        mMutex = SDL_CreateMutex();
    }

    Mutex::~Mutex()
    {
        SDL_DestroyMutex(mMutex);
    }

    void Mutex::lock()
    {
        SDL_mutexP(mMutex);
    }

    void Mutex::unlock()
    {
        SDL_mutexV(mMutex);
    }
}

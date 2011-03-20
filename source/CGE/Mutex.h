#ifndef MUTEX_H
#define MUTEX_H

#include <SDL_mutex.h>

namespace CGE
{
    class Mutex
    {
        public:
            Mutex();
            ~Mutex();

            void lock();
            void unlock();

        private:
            SDL_mutex* mMutex;
    };
}

#endif

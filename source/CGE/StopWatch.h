#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <SDL.h>

namespace CGE
{
    class StopWatch
    {
        public:
            StopWatch();
            ~StopWatch();

            Uint32 read();

            void start();
            void stop();
            void reset();

        private:
            void update();

            Uint32 mTotal;
            Uint32 mCurrent;
    };
}

#endif

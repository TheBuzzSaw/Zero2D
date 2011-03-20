#ifndef MUSIC_H
#define MUSIC_H

#include <SDL.h>
#include <SDL_mixer.h>

namespace CGE
{
    class Music
    {
        public:
            Music();
            Music(const char* inFile);
            ~Music();

            void increaseVolume();
            void decreaseVolume();
            void setVolume(int inVolume);

            void load(const char* inFile);
            void play();
            void stop();

        private:
            Mix_Music* mMusic;
            int mVolume;
    };
}

#endif

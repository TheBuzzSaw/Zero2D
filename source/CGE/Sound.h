#ifndef SOUND_H
#define SOUND_H

#include <SDL_mixer.h>
#include <cmath>
#include <iostream>

#define NUM_CHANNELS 32

namespace CGE
{
    class Sound
    {
        public:
            Sound();
            Sound(const char* inFile);
            ~Sound();

            void load(const char* inFile);
            void play() const;
            void playFromPosition(int inAngle, int inDistance);
            void setVolume(float inVolume);
            void increaseVolume();
            void decreaseVolume();

            static void setMasterVolume(float inVolume);
            static void increaseMasterVolume();
            static void decreaseMasterVolume();

        private:
            Sound(const Sound& inSound)
            {
                // no copying
            }

            Sound& operator=(const Sound& inSound)
            {
                // no copying
                return *this;
            }

            Mix_Chunk* mSound;
            float mVolume;

            static float mMasterVolume;
            static int mChannel;
    };
}

#endif

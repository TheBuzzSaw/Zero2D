#include "Music.h"
#include "Exception.h"

namespace CGE
{
    Music::Music() : mMusic(NULL), mVolume(20)
    {
        Mix_VolumeMusic(mVolume);
    }

    Music::Music(const char* inFile) : mMusic(NULL), mVolume(20)
    {
        Mix_VolumeMusic(mVolume);
        load(inFile);
    }

    Music::~Music()
    {
        if (Mix_PlayingMusic())
            Mix_HaltMusic();

        Mix_FreeMusic(mMusic); // safe to call on NULL value
    }


    void Music::increaseVolume()
    {
        mVolume += 5;

        if (mVolume > 128)
        {
            mVolume = 128;
        }
        Mix_VolumeMusic(mVolume);
    }


    void Music::decreaseVolume()
    {
        mVolume -= 5;

        if (mVolume < 0)
        {
            mVolume = 0;
        }
        Mix_VolumeMusic(mVolume);
    }

    void Music::setVolume(int inVolume)
    {
        mVolume = inVolume;

        if (mVolume > 128)
        {
            mVolume = 128;
        }
        else if (mVolume < 0)
        {
            mVolume = 0;
        }

        Mix_VolumeMusic(mVolume);
    }


    void Music::load(const char* inFile)
    {
        static const char* functionName = "Music::load";

        if (!inFile || !*inFile)
            throw Exception(functionName, "invalid file");

        if ((mMusic = Mix_LoadMUS(inFile)) == NULL)
        {
            std::string message(Mix_GetError());
            message += ' ';
            message += inFile;

            throw Exception(functionName, message);
        }
    }

    void Music::play()
    {
        static const char* functionName = "Music::play";

        if (!mMusic) return;

        if (!Mix_PlayingMusic())
        {
            // This begins playing the music - the first argument is a
            // pointer to Mix_Music structure, and the second is how many
            // times you want it to loop (use -1 for infinite, and 0 to
            // have it just play once)
            if ((Mix_PlayMusic(mMusic, -1)) == -1)
                throw Exception(functionName, Mix_GetError());
        }
    }

    void Music::stop()
    {
        if (Mix_PlayingMusic())
            Mix_HaltMusic();
    }

}

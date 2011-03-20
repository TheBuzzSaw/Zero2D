#include "Sound.h"
#include "Exception.h"

namespace CGE
{
    int Sound::mChannel = 1;
    float Sound::mMasterVolume = 1.0f;

    const float MAX_VOLUME = static_cast<float>(MIX_MAX_VOLUME);

    Sound::Sound() : mSound(NULL), mVolume(1.0f)
    {
    }

    Sound::Sound(const char* inFile) : mSound(NULL), mVolume(1.0f)
    {
        load(inFile);
    }

    Sound::~Sound()
    {
        Mix_FreeChunk(mSound); // safe to call on NULL value
    }

    void Sound::load(const char* inFile)
    {
        static const char* functionName = "Sound::load";

        if (!inFile || !*inFile)
            throw Exception(functionName, "invalid file");

        if ((mSound = Mix_LoadWAV(inFile)) == NULL)
            throw Exception(functionName, Mix_GetError());
    }

    void Sound::play() const
    {
        static const char* functionName = "Sound::play";

        // We only want to throw an exception if there is a valid sound to be
        // played.
        if (!mSound) return;

        if (Mix_PlayChannel(mChannel, mSound, 0) == -1)
            throw Exception(functionName, Mix_GetError());

        mChannel = (mChannel + 1) % NUM_CHANNELS;
    }

    void Sound::playFromPosition(int inAngle, int inDistance)
    {
        static const char* functionName = "Sound::playFromPosition";
        if (!mSound) return;

        if (!Mix_SetPosition(mChannel, inAngle, inDistance))
            throw Exception(functionName, Mix_GetError());

        if (Mix_PlayChannel(mChannel, mSound, 0) == -1)
            throw Exception(functionName, Mix_GetError());

        mChannel = (mChannel + 1) % NUM_CHANNELS;
    }

    void Sound::setVolume(float inVolume)
    {
        mVolume = std::min(1.0f, std::max(0.0f, inVolume));
        Mix_VolumeChunk(mSound, int(mVolume * MAX_VOLUME));
    }

    void Sound::increaseVolume()
    {
        setVolume(mVolume + 0.05f);
    }

    void Sound::decreaseVolume()
    {
        setVolume(mVolume - 0.05f);
    }

    void Sound::increaseMasterVolume()
    {
        setMasterVolume(mMasterVolume + 0.05);
    }

    void Sound::decreaseMasterVolume()
    {
        setMasterVolume(mMasterVolume - 0.05);
    }

    void Sound::setMasterVolume(float inVolume)
    {
        mMasterVolume = std::min(1.0f, std::max(0.0f, inVolume));
        Mix_Volume(-1, int(mMasterVolume * MAX_VOLUME));
    }

}

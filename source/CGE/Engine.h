#ifndef ENGINE_H
#define ENGINE_H

#include "Graphics.h"
#include "ManagedModule.h"

#include <iostream>

namespace CGE
{

    class Engine
    {
        public:
            struct Settings
            {
                Settings() :
                    windowTitle(NULL),
                    windowTitle2(NULL),
                    iconPath(NULL),
                    sound(true),
                    frameLength(25) {}

                const char* windowTitle;
                const char* windowTitle2;
                const char* iconPath;
                bool sound;
                Uint32 frameLength;
            };

            Engine(const Settings& inSettings = Settings());
            ~Engine();

            void run(Module& inModule);
            void manage(ManagedModule* inModule);

        private:
            void initialize();

            PropertyList mConfig;
            Surface mDisplay;
            Surface mWindowIcon;
            SDL_Rect** mModes;
            Settings mSettings;

            static void logOpenGL(std::ostream& inStream);
            static void prepareFiles();
            static const char* logFile;
            static const char* configFile;
    };
}

#endif

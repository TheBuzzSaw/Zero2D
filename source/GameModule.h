#ifndef GAMEMODULE_H
#define GAMEMODULE_H

#include "Sheet.h"

#include <CGE/Module.h>

class GameModule : public CGE::Module
{
    public:
        GameModule();
        virtual ~GameModule();

        /// module operation
        virtual void onOpen();
        virtual void onClose();
        virtual void onLoop();
        virtual void onPulse();
        virtual void onSecond(Uint32 inFramesPerSecond);

        virtual void onResize(int inWidth, int inHeight);

    protected:
    private:
        Sheet mSheet;
};

#endif

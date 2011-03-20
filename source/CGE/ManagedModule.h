#ifndef MANAGEDMODULE_H
#define MANAGEDMODULE_H

#include "Module.h"
#include "PropertyList.h"

namespace CGE
{
    class ManagedModule : public Module
    {
        public:
            ManagedModule();
            virtual ~ManagedModule();

            inline bool isDead() const { return mDead; }
            inline ManagedModule* nextModule() const { return mNextModule; }

            /// module operation
            virtual void onLoad(PropertyList& inList);
            virtual void onUnload();


        protected:
            bool mDead;
            ManagedModule* mNextModule;
    };
}

#endif

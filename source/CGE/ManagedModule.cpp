#include "ManagedModule.h"

namespace CGE
{
    ManagedModule::ManagedModule() : mDead(true), mNextModule(NULL)
    {
    }

    ManagedModule::~ManagedModule()
    {
    }

    void ManagedModule::onLoad(PropertyList& inList)
    {
    }

    void ManagedModule::onUnload()
    {
    }
}

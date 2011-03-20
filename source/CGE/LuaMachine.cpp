#include "LuaMachine.h"
#include <iostream>

namespace CGE
{
    LuaMachine::LuaMachine() : mLuaState(luaL_newstate())
    {
        luaL_openlibs(mLuaState); // massive security hole
    }

    LuaMachine::~LuaMachine()
    {
        lua_close(mLuaState);
    }

    void LuaMachine::addFunction(const char* inName, lua_CFunction inFunction)
    {
        lua_register(mLuaState, inName, inFunction);
    }

    void LuaMachine::reportErrors()
    {
        if (mStatus)
        {
            mError = "-- ";
            mError += lua_tostring(mLuaState, -1);
            std::cerr << mError << '\n';
            lua_pop(mLuaState, 1); // remove error message
        }
    }

    void LuaMachine::execute()
    {
        mStatus = lua_pcall(mLuaState, 0, LUA_MULTRET, 0);
        if (mStatus) reportErrors();
    }

    void LuaMachine::loadFile(const char* inFile)
    {
        mStatus = luaL_loadfile(mLuaState, inFile);
        if (mStatus)
            reportErrors();
        else
            execute();
    }

    void LuaMachine::runCommand(const char* inCommand)
    {
        mStatus = luaL_loadstring(mLuaState, inCommand);
        if (mStatus)
            reportErrors();
        else
            execute();
    }
}

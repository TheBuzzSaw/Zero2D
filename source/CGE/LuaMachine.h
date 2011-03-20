#ifndef LUAMACHINE_H
#define LUAMACHINE_H

#include <lua.hpp>
#include <string>

namespace CGE
{
    class LuaMachine
    {
        public:
            LuaMachine();
            virtual ~LuaMachine();

            void loadFile(const char* inFile);
            void runCommand(const char* inCommand);
            void addFunction(const char* inName, lua_CFunction inFunction);

        private:
            void execute();
            void reportErrors();

            lua_State* mLuaState;
            int mStatus;
            std::string mError;
    };
}

#endif

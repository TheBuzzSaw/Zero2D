#include <CGE/Engine.h>
#include "TestModule.h"

int main(int argc, char** argv)
{
    CGE::Engine::Settings s;
    s.sound = false;
    s.windowTitle = "Zero2D";

    CGE::Engine e(s);

    {
        TestModule tm;
        e.run(tm);
    }

    return 0;
}

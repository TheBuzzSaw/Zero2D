#include "Sprite.h"
#include "GameModule.h"
#include <CGE/Engine.h>
#include <CGE/Heap.h>

int main(int argc, char** argv)
{
    {
        CGE::Engine::Settings s;
        s.windowTitle = "Zero2D";

        CGE::Engine e(s);

        GameModule gm;

        e.run(gm);

        //Sprite sprite("data/images/");
    }

    CGE::Heap::dump();

    return 0;
}

#include "Sprite.h"
#include <CGE/Engine.h>
#include <CGE/Heap.h>

int main(int argc, char** argv)
{
    {
        CGE::Engine::Settings s;
        s.windowTitle = "Zero2D";

        CGE::Engine e(s);

        //CGE::Module m;

        //e.run(m);

        Sprite sprite("data/images/");
    }

    CGE::Heap::dump();

    return 0;
}

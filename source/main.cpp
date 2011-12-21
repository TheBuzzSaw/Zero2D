#include <CGE/Engine.h>

int main(int argc, char** argv)
{
    CGE::Engine::Settings s;
    s.windowTitle = "Zero2D";

    CGE::Engine e(s);

    CGE::Module m;

    e.run(m);
    return 0;
}

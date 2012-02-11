#ifndef SPRITEBIN_H
#define SPRITEBIN_H

#include "RenderBin2D.h"
#include <CGE/OpenGL/Program.h>

class SpriteBin : public RenderBin2D
{
    public:
        SpriteBin();
        virtual ~SpriteBin();

    protected:
        virtual void willRender();
        virtual void render(Actor2D* inActor);

    private:
        CGE::Program<2> mProgram;
};

#endif

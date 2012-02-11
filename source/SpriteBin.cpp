#include "SpriteBin.h"
#include "SpriteActor.h"
#include <CGE/OpenGL/VertexShader.h>
#include <CGE/OpenGL/FragmentShader.h>

SpriteBin::SpriteBin()
{
    CGE::VertexShader vs;
    CGE::FragmentShader fs;
}

SpriteBin::~SpriteBin()
{
}

void SpriteBin::willRender()
{
}

void SpriteBin::render(Actor2D* inActor)
{
    SpriteActor* actor = static_cast<SpriteActor*>(inActor);
}

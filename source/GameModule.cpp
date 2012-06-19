#include "GameModule.h"
#include <CGE/Matrix4x4.h>

GameModule::GameModule() : mSheet("data/images/smb3.png")
{
}

GameModule::~GameModule()
{
}

void GameModule::onOpen()
{
    glClearColor(0.0f, 0.2f, 0.2f, 1.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void GameModule::onClose()
{
    glDisable(GL_BLEND);
}

void GameModule::onLoop()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    mSheet.display(4, 82, 16, 27);
}

void GameModule::onPulse()
{

}

void GameModule::onSecond(Uint32 inFramesPerSecond)
{

}

void GameModule::onResize(int inWidth, int inHeight)
{
    float ratio = float(inWidth) / float(inHeight);
    CGE::Matrix4x4<float> projection;
    projection.orthographic(float(inHeight / 16), ratio);

    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(projection);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

#include "TestModule.h"

TestModule::TestModule() : mRotation(0.0f), mSM("data/images/"), mSprite(mSM)
{
}

TestModule::~TestModule()
{
}

void TestModule::onOpen()
{
    glEnable(GL_TEXTURE_2D);
    mTexture.bind();
    glClearColor(0.5f, 0.0f, 0.0f, 1.0f);
}

void TestModule::onClose()
{
    glDisable(GL_TEXTURE_2D);
}

void TestModule::onLoop()
{
    glClear(GL_COLOR_BUFFER_BIT);

    mModelView.loadIdentity();
    mModelView.rotateZ(mRotation);
    glLoadMatrixf(mModelView);
}

void TestModule::onPulse()
{
    mRotation += 1.0f;
    if (mRotation > 180.0f) mRotation -= 360.0f;
}

void TestModule::onSecond(Uint32 inFramesPerSecond)
{
}

void TestModule::onResize(int inWidth, int inHeight)
{
    glViewport(0, 0, inWidth, inHeight);

    float ratio = static_cast<float>(inWidth) / static_cast<float>(inHeight);
    mProjection.loadIdentity();
    mProjection.orthographic(2.0f, ratio);
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(mProjection);
    glMatrixMode(GL_MODELVIEW);
}

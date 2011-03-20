#ifndef TESTMODULE_H
#define TESTMODULE_H

#include <CGE/Module.h>
#include <CGE/Texture2D.h>
#include <CGE/VertexBufferObject.h>
#include <CGE/IndexVBO.h>
#include <CGE/Matrix4x4.h>

#include "Sprite.h"

class TestModule : public CGE::Module
{
    public:
        TestModule();
        virtual ~TestModule();

        /// module operation
        virtual void onOpen();
        virtual void onClose();
        virtual void onLoop();
        virtual void onPulse();
        virtual void onSecond(Uint32 inFramesPerSecond);

        virtual void onResize(int inWidth, int inHeight);

    private:
        CGE::VertexBufferObject mVertexVBO;
        CGE::VertexBufferObject mTextureVBO;
        CGE::IndexVBO mIndexVBO;
        CGE::Texture2D mTexture;

        CGE::Matrix4x4<GLfloat> mProjection;
        CGE::Matrix4x4<GLfloat> mModelView;

        float mRotation;

        SpriteMeta mSM;
        Sprite mSprite;
};

#endif

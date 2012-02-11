#ifndef ACTOR2D_H
#define ACTOR2D_H

#include <CGE/SceneGraphNode.h>

class RenderBin2D;

class Actor2D : public CGE::SceneGraphNode
{
    public:
        friend class RenderBin2D;

        Actor2D();
        virtual ~Actor2D();

        void removeFromBin();

    protected:
    private:
        RenderBin2D* mRenderBin;
        Actor2D* mNextActor;
        Actor2D* mPreviousActor;
};

#endif

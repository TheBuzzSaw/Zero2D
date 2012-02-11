#ifndef RENDERBIN2D_H
#define RENDERBIN2D_H

class Actor2D;

class RenderBin2D
{
    public:
        friend class Actor2D;

        RenderBin2D();
        virtual ~RenderBin2D();

        void addActor(Actor2D* inActor);
        void renderAll();

    protected:
        virtual void willRender();
        virtual void didRender();
        virtual void render(Actor2D* inActor) = 0;

    private:
        Actor2D* mFirstActor;
};

#endif

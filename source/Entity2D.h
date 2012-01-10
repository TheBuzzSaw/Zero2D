#ifndef ENTITY2D_H
#define ENTITY2D_H

#include <CGE/Vectors.h>
#include <CGE/LuaReference.h>

class Entity2D
{
    public:
        Entity2D(const CGE::LuaReference& inLuaTable);
        virtual ~Entity2D();

        void update();

        /// getters
        inline const vec3f& translation() const { return mTranslation; }
        inline const vec2d& position() const { return mPosition; }
        inline const vec2d& velocity() const { return mVelocity; }

        /// setters
        inline void position(double* inPosition) { mPosition = inPosition; }
        inline void velocity(double* inVelocity) { mVelocity = inVelocity; }

        void position(double inX, double inY);
        void velocity(double inX, double inY);

        void move(double inX, double inY);
        void accelerate(double inX, double inY);

    protected:
    private:
        double mMass;
        vec2d mPosition;
        vec2d mVelocity;
        vec3f mTranslation;

        CGE::LuaReference mLuaTable;
};

#endif

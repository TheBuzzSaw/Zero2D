#include "Entity2D.h"
#include <cassert>

Entity2D::Entity2D(const CGE::LuaReference& inLuaTable) : mMass(0.0),
    mLuaTable(inLuaTable)
{
}

Entity2D::~Entity2D()
{
}

void Entity2D::update()
{
    mPosition[0] += mVelocity[0];
    mPosition[1] += mVelocity[1];

    mTranslation[0] = mPosition[0];
    mTranslation[1] = mPosition[1];
}

void Entity2D::position(double inX, double inY)
{
    mPosition[0] = inX;
    mPosition[1] = inY;
}

void Entity2D::velocity(double inX, double inY)
{
    mVelocity[0] = inX;
    mVelocity[1] = inY;
}

void Entity2D::move(double inX, double inY)
{
    mPosition[0] += inX;
    mPosition[1] += inY;
}

void Entity2D::accelerate(double inX, double inY)
{
    mVelocity[0] += inX;
    mVelocity[1] += inY;
}

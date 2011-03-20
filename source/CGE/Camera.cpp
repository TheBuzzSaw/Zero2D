#include "Camera.h"

namespace CGE
{
    Camera::Camera() : mDistance(0.0f), mRotation(0.0f), mAngle(0.0f)
    {
    }

    Camera::~Camera()
    {
    }

    void Camera::update()
    {
        mMatrix.loadIdentity();
        if (mDistance > 0.0f) mMatrix.translate(0.0f, 0.0f, -mDistance);
        mMatrix.rotateX(mAngle);
        mMatrix.rotateZ(mRotation);
        mMatrix.translate(-mPosition[0], -mPosition[1], -mPosition[2]);
    }

    void Camera::setDistance(float inDistance)
    {
        if (inDistance < 0.0f)
            mDistance = 0.0f;
        else
            mDistance = inDistance;
    }

    void Camera::setRotation(float inRotation)
    {
        if (inRotation < 0.0f)
            inRotation = fmod(inRotation - 180.0f, 360.0f) + 180.0f;
        else
            inRotation = fmod(inRotation + 180.0f, 360.0f) - 180.0f;
    }

    void Camera::setAngle(float inAngle)
    {
        if (inAngle < 0.0f)
            inAngle = fmod(inAngle - 180.0f, 360.0f) + 180.0f;
        else
            inAngle = fmod(inAngle + 180.0f, 360.0f) - 180.0f;
    }
}

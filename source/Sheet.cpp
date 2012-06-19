#include "Sheet.h"

Sheet::Sheet(const char* inPath)
{
    CGE::Image image(inPath);
    mWidth = image.width();
    mHeight = image.height();

    mTexture.loadImage(image);
}

Sheet::~Sheet()
{
}

void Sheet::display(int inX, int inY, int inW, int inH)
{
    float w = float(mWidth - 1);
    float h = float(mHeight - 1);

    float ulx = float(inW) / -2.0f;
    float uly = float(inH) / 2.0f;
    float uls = float(inX) / w;
    float ult = float(inY) / h;

    float lrx = -ulx;
    float lry = -uly;
    float lrs = float(inX + inW) / w;
    float lrt = float(inY + inH) / h;

    // immediate mode just for testing accuracy of coordinates
    glEnable(GL_TEXTURE_2D);
    mTexture.bind();
    glBegin(GL_TRIANGLE_FAN);

    glTexCoord2f(uls, ult);
    glVertex2f(ulx, uly);

    glTexCoord2f(lrs, ult);
    glVertex2f(lrx, uly);

    glTexCoord2f(lrs, lrt);
    glVertex2f(lrx, lry);

    glTexCoord2f(uls, lrt);
    glVertex2f(ulx, lry);

    glEnd();
    glDisable(GL_TEXTURE_2D);
}

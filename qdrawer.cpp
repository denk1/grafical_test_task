#include "qdrawer.h"

QDrawer::QDrawer(int width, int height): width_(width), height_(height)
{

}

QPoint QDrawer::convertPointIntoScreenCooords(float x, float y)
{
    return QPoint(width_/2 + (int)(x/RIGHT_BORDER * (float)(width_/2)),  height_/2 + (int)(y/FRONT_BORDER * (float)(height_/2)));
}

QPoint QDrawer::convertPointIntoScreenDistance(float x, float y)
{
    return QPoint( x/RIGHT_BORDER * width_, y/FRONT_BORDER * height_);
}

#ifndef QDRAWER_H
#define QDRAWER_H
#include <QPainter>

class QDrawer
{
public:
    QDrawer(int width, int heigth);
    QPoint convertPointIntoScreenCooords(float x, float y);
    QPoint convertPointIntoScreenDistance(float x, float y);
    QDrawer& operator=(QDrawer& drawer) {
        return drawer;
    }
private:
    int width_;
    int height_;
    float FRONT_BORDER = 30;
    float REAR_BORDER = -30;
    float LEFT_BORDER = -25;
    float RIGHT_BORDER = 25;
};

#endif // QDRAWER_H

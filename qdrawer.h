#ifndef QDRAWER_H
#define QDRAWER_H
#include <QPainter>

class QDrawer
{
public:
    QDrawer(QPainter& painter, int width, int heigth);
private:
    QPainter& qPainter_;
    int width_;
    int heigth_;
};

#endif // QDRAWER_H

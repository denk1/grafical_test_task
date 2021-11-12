#ifndef ROADMARKINGSTRAFFICOBJECT_H
#define ROADMARKINGSTRAFFICOBJECT_H
#include <QPainter>
#include <QVector>
#include <QLine>
#include "trafficobject.h"

class RoadMarkingsTrafficObject : public TrafficObject
{
public:
    RoadMarkingsTrafficObject(int widgetWidth, int widgetHeight);
    void draw(QPainter& painter);
private:
    QVector<QLine> lines_;
};

#endif // ROADMARKINGSTRAFFICOBJECT_H

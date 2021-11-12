#ifndef ROADOBJECTPAINTER_H
#define ROADOBJECTPAINTER_H
#include<QPainter>
#include<QList>
#include "trafficobject.h"

class RoadObjectPainter
{
public:
    RoadObjectPainter();
    void drawObjects(QPainter& qPainter, QList<TrafficObject*>& listTrafficObjects);
};

#endif // ROADOBJECTPAINTER_H

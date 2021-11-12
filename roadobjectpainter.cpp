#include "roadobjectpainter.h"

RoadObjectPainter::RoadObjectPainter()
{

}

void RoadObjectPainter::drawObjects(QPainter &qPainter, QList<TrafficObject*> &listTrafficObjects)
{
    for(TrafficObject* trfObj :listTrafficObjects) {
        trfObj->draw(qPainter);
    }
}

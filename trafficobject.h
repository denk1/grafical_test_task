#ifndef TRAFFICOBJECT_H
#define TRAFFICOBJECT_H
#include<QPainter>
#include "qdrawer.h"

class TrafficObject
{
public:
    TrafficObject();
    virtual ~TrafficObject() {};
    virtual void draw(QPainter& painter) = 0;
private:

};

#endif // TRAFFICOBJECT_H

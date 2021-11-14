#ifndef VEHICLETRAFFICOBJECT_H
#define VEHICLETRAFFICOBJECT_H

#include "trafficobject.h"
#include "qdrawer.h"

class VehicleTrafficObject : public TrafficObject
{
public:
    VehicleTrafficObject(QDrawer& drawer);
    VehicleTrafficObject(QDrawer& drawer, QPointF position);
    VehicleTrafficObject(QDrawer& drawer, QPointF position, float w, float l);
    void draw(QPainter& painter);
    void setDrawer(QDrawer& drawer) {
        qDrawer_ = drawer;
    }
private:
    QPointF position_;
    float w_, l_;
    QDrawer& qDrawer_;
};

#endif // VEHICLETRAFFICOBJECT_H

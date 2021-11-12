#ifndef VEHICLETRAFFICOBJECT_H
#define VEHICLETRAFFICOBJECT_H

#include "trafficobject.h"

class VehicleTrafficObject : public TrafficObject
{
public:
    VehicleTrafficObject();
    VehicleTrafficObject(QPoint position);
    void draw(QPainter& painter);
private:
    QPoint position_;
};

#endif // VEHICLETRAFFICOBJECT_H

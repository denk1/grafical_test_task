#include "vehicletrafficobject.h"

VehicleTrafficObject::VehicleTrafficObject():position_()
{

}

VehicleTrafficObject::VehicleTrafficObject(QPoint position)
{
    position_ = position;
}

void VehicleTrafficObject::draw(QPainter &painter)
{

}

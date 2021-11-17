#include "vehicletrafficobject.h"

VehicleTrafficObject::VehicleTrafficObject(QDrawer& drawer):position_(), w_(2.0f), l_(4.0f), qDrawer_(drawer)
{

}

VehicleTrafficObject::VehicleTrafficObject(QDrawer& drawer, QPointF position):  w_(2.0f), l_(4.0f), qDrawer_(drawer)
{
    position_ = position;
}

VehicleTrafficObject::VehicleTrafficObject(QDrawer& drawer, QPointF position, float w, float l):position_(position), w_(w), l_(l), qDrawer_(drawer)
{

}

void VehicleTrafficObject::draw(QPainter &painter)
{
    QPoint point = qDrawer_.convertPointIntoScreenCooords(position_.x(), position_.y());
    QPoint point_hull = qDrawer_.convertPointIntoScreenDistance( w_ * 2.0f, l_ * 2.0f);
    painter.drawRect(point.x() - point_hull.x()/2, point.y() - point_hull.y()/2, point_hull.x(), point_hull.y());
}

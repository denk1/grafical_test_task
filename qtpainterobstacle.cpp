#include <QStringLiteral>
#include <QList>
#include "qtpainterobstacle.h"
#include "qdrawer.h"
#include "vehicletrafficobject.h"

using namespace std;


QtPainterObstacle::QtPainterObstacle(QPainter* painter):
    _painter(painter), _widgetHeight(0), _widgetWidth(0),
    acc( tag::rolling_window::window_size = 1500)
{
    _prev_time_point = chrono::system_clock::now();
}

void QtPainterObstacle::draw(QWidget *widget)
{
    QPainter painter(widget);
    _widgetHeight = widget->height();
    _widgetWidth = widget->width();


    drawGrid(painter);
}

QList<TrafficObject *> &QtPainterObstacle::getDynamicObjects()
{
    return dynamicObjs_;
}

int QtPainterObstacle::getScreenX(float x)
{
     return (x + 2.5) / 5.0 * static_cast<float>(_widgetWidth);
}

int QtPainterObstacle::getScreenY(float z)
{
    return _widgetHeight - static_cast<int>(z/5.0 * static_cast<float>(_widgetHeight));
}

void QtPainterObstacle::drawGrid(QPainter &qPainter)
{
    RoadObjectPainter roadObjPainter;
    RoadMarkingsTrafficObject roadMarkingsTrafficObject(_widgetWidth, _widgetHeight);
    QList<TrafficObject*> listTrfObjs;
    QDrawer drawer(_widgetWidth, _widgetHeight);
    VehicleTrafficObject vehicle(drawer, QPointF(0, 0), 1.8f, 4.4f);
    listTrfObjs.append(&roadMarkingsTrafficObject);
    listTrfObjs.append(&vehicle);
    std::lock_guard<std::mutex> guard(mutex_);
    listTrfObjs.append(dynamicObjs_);
    roadObjPainter.drawObjects(qPainter, listTrfObjs);

}

void QtPainterObstacle::setFPS(QPainter &painter)
{
    auto time_point_now = chrono::system_clock::now();
    int duration =  std::chrono::duration_cast<std::chrono::microseconds>(time_point_now - _prev_time_point).count();
    int fps = 1000000 / duration;
    acc(double(fps));
    QFont font = painter.font();
    font.setPointSize(font.pointSize() * 2);
    painter.setPen(QPen(Qt::blue, 125, Qt::DashDotLine, Qt::RoundCap));
    painter.setFont(font);
    fps = static_cast<int>(rolling_mean(acc));
    QString strFps = QStringLiteral("%1 FPS").arg(fps);
    painter.drawText(QPoint(15, 35), strFps);
    _prev_time_point = time_point_now;
}

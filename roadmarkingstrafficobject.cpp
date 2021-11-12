#include "roadmarkingstrafficobject.h"

RoadMarkingsTrafficObject::RoadMarkingsTrafficObject(int widgetWidth, int widgetHeight)
{
    int vLineStep = widgetWidth/3;
    int xCurr = 0;
    QVector<QLine> lines;

    for(int i = 0; i < 5; i++) {
        lines_.append(QLine(QPoint( xCurr, 0), QPoint(xCurr, widgetHeight)));
        xCurr += vLineStep;
    }
}

void RoadMarkingsTrafficObject::draw(QPainter& painter)
{
    painter.setPen(QPen(QColor(255, 255, 255, 128), 2, Qt::SolidLine, Qt::RoundCap));
    painter.drawLines(lines_);
}

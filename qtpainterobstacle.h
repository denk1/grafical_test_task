#ifndef QTPAINTEROBSTACLE_H
#define QTPAINTEROBSTACLE_H

#include <chrono>
#include <QPainter>
#include <QWidget>
#include <mutex>
#include "painterobstacle.h"
#include "roadmarkingstrafficobject.h"
#include "roadobjectpainter.h"
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/stats.hpp>
#include <boost/accumulators/statistics/mean.hpp>
#include <boost/accumulators/statistics/moment.hpp>
#include <boost/accumulators/statistics/tail.hpp>
#include <boost/accumulators/statistics_fwd.hpp>
#include <boost/accumulators/statistics/rolling_mean.hpp>

using namespace boost::accumulators;
class QtPainterObstacle : public PainterObstacle
{
public:
    QtPainterObstacle(QPainter* painter);
    void draw(QWidget* widget ) override;
    QList<TrafficObject*>& getDynamicObjects();
    int getWidgetHeight() {
        return _widgetHeight;
    }

    int getWidgetWidth() {
        return _widgetWidth;
    }

    std::mutex &getMutex() {
        return mutex_;
    }

private:
    int getScreenX(float x);
    int getScreenY(float y);
    void drawGrid(QPainter& qPainter);
    void setFPS(QPainter& qPainter);

    QPainter* _painter;
    QWidget* _ptrWidget;
    int _widgetHeight;
    int _widgetWidth;
    const int SHIFT_TITILE = 15;
    std::chrono::system_clock::time_point _prev_time_point;
    accumulator_set<double, stats<tag::rolling_mean> >  acc;
    QList<TrafficObject*> dynamicObjs_;
    std::mutex mutex_;
};

#endif // QTPAINTEROBSTACLE_H

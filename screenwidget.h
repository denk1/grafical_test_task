#ifndef SCREENWIDGET_H
#define SCREENWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include "qtpainterobstacle.h"
#include "tcpsocket.h"

class ScreenWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ScreenWidget(QWidget *parent = nullptr);

signals:


private:
    void paintEvent(QPaintEvent *event) override;
    QPainter painter;
    QtPainterObstacle painterObstacle;
    TcpSocket tcpSocket;
    QTimer timer_;
};

#endif // SCREENWIDGET_H

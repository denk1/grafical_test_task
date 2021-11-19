#include "screenwidget.h"


ScreenWidget::ScreenWidget(QWidget *parent) :
    QWidget(parent),
    painter(this),
    painterObstacle(&painter),
    tcpSocket(nullptr, &painterObstacle)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::black);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    QSizePolicy sizePolicy;
    sizePolicy.setHorizontalPolicy(QSizePolicy::Expanding);
    sizePolicy.setVerticalPolicy(QSizePolicy::Expanding);
    this->setSizePolicy(sizePolicy);
    connect(&timer_,SIGNAL(timeout()),this, SLOT(update()));
        timer_.start(50);
    tcpSocket.doConnect();

}

void ScreenWidget::paintEvent(QPaintEvent *event)
{
    painterObstacle.draw(this);
}

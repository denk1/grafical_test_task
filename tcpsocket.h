#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include "qtpainterobstacle.h"
#include "qdrawer.h"


class TcpSocket : public QObject
{
    Q_OBJECT
public:
    explicit TcpSocket(QObject *parent = nullptr, QtPainterObstacle* painterObstacle = nullptr);
    void doConnect();

signals:
public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64);
    void readyRead();

private:
    QTcpSocket * socket;
    QtPainterObstacle* ptrPainterObstacle_;
    QList<QDrawer*> listDrawers_;
};

#endif // TCPSOCKET_H

#include "tcpsocket.h"
#include "vehicletrafficobject.h"


uint32_t decodeFromBigEndian(char* ptr) {
    uint32_t data = static_cast<uint32_t>(ptr[0]);
    data = data << 8;
    data += static_cast<uint32_t>(ptr[1]);
    data = data << 8;
    data += static_cast<uint32_t>(ptr[2]);
    data = data << 8;
    data += static_cast<uint32_t>(ptr[3]);
    return data;
}

TcpSocket::TcpSocket(QObject *parent, QtPainterObstacle* painterObstacle) : QObject(parent), ptrPainterObstacle_(painterObstacle)
{

}

void TcpSocket::doConnect()
{
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));

    qDebug() << "Connecting,..";

    socket->connectToHost("localhost", 36217);

    if(socket->state() == QAbstractSocket::UnconnectedState
            || socket->waitForDisconnected(1000)) {
                qDebug("Disconnected!");
    }
}

void TcpSocket::connected()
{
    qDebug() << "connection";
}

void TcpSocket::disconnected()
{
    qDebug() << "disconnected";
}

void TcpSocket::bytesWritten(qint64)
{
    qDebug() << "bytesWritten";
}

void TcpSocket::readyRead()
{
    int count = 0;
    qDebug() << "readyRead";
    QByteArray qByteArray = socket->readAll();
    if( 4 == (int)qByteArray[0] && 92 == (int)qByteArray[1]) {
        count = (int)qByteArray[2];
    }
    /*
    for(TrafficObject* ptrVhcTraffObj : ptrPainterObstacle_->getDynamicObjects())
        delete ptrVhcTraffObj;
    for(QDrawer* ptrDrawer : listDrawers_)
        delete ptrDrawer;
    */
    ptrPainterObstacle_->getDynamicObjects().clear();
    qByteArray.remove(0, 3);
    QDataStream ds(&qByteArray, QIODevice::ReadOnly);
    ds.setFloatingPointPrecision(QDataStream::SinglePrecision);
    qDebug() << count;
    char* ch;
    for(int i = 0; i < count*24; i+=24) {

        int id = 0;
        float x = 0.0, y = 0.0, w = 0.0, l = 0.0;
        ds >> id;
        ch = reinterpret_cast<char*>(&id);
        id = decodeFromBigEndian(ch);
        qDebug() << id;
        ds >> x >> y >> w >> l;

        qDebug() << id << x << y << w << l;

        //QDrawer* ptrDrawer = new QDrawer(ptrPainterObstacle_->getWidgetHeight(), ptrPainterObstacle_->getWidgetWeight());
        //ptrPainterObstacle_->getDynamicObjects().append(new VehicleTrafficObject(*ptrDrawer));
    }

}



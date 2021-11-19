#include "tcpsocket.h"
#include "vehicletrafficobject.h"

uint32_t decodeFromBigEndian(unsigned char* ptr) {
    uint32_t data = static_cast<uint32_t>(ptr[0]);
    data = data << 8;
    data += static_cast<uint32_t>(ptr[1]);
    data = data << 8;
    data += static_cast<uint32_t>(ptr[2]);
    data = data << 8;
    data += static_cast<uint32_t>(ptr[3]);
    return data;
}

template<class T>
T convertToLitleEndian(T v) {
    unsigned char* ch = {};
    ch = reinterpret_cast<unsigned char*>(&v);
    unsigned int s = decodeFromBigEndian(ch);
    return *reinterpret_cast<T*>(&s);
}

float ReverseFloat( const float inFloat )
{
   float retVal;
   char *floatToConvert = ( char* ) & inFloat;
   char *returnFloat = ( char* ) & retVal;

   // swap the bytes into a temporary buffer
   returnFloat[0] = floatToConvert[3];
   returnFloat[1] = floatToConvert[2];
   returnFloat[2] = floatToConvert[1];
   returnFloat[3] = floatToConvert[0];

   return retVal;
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

    socket->connectToHost("localhost", 36215);

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
    uint8_t count = 0;
    qDebug() << "readyRead";
    QByteArray qByteArray = socket->readAll();
    if( 4 == (int)qByteArray[0] && 92 == (int)qByteArray[1]) {
        count = qByteArray[2];
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
    std::lock_guard guard(ptrPainterObstacle_->getMutex());
    for(auto i : listDrawers_)
        delete i;
    listDrawers_.erase(listDrawers_.begin(), listDrawers_.end());
    ptrPainterObstacle_->getDynamicObjects().erase(ptrPainterObstacle_->getDynamicObjects().begin(), ptrPainterObstacle_->getDynamicObjects().end());
    for(int i = 0; i < count*24; i+=24) {

        unsigned int id = 0;
        float speed =0,  x = 0.0, y = 0.0, w = 0.0, l = 0.0;
        ds >> id;
        ch = reinterpret_cast<char*>(&id);
        id = *reinterpret_cast<int*>(ch);
        qDebug() << id;
        ds >> speed >> x >> y >> w >> l;

        speed = convertToLitleEndian(speed);
        x = convertToLitleEndian(x);
        y = convertToLitleEndian(y);
        w = convertToLitleEndian(w);
        l = convertToLitleEndian(l);
        /*
        speed = ReverseFloat(speed);
        x = ReverseFloat(x);
        y = ReverseFloat(y);
        w = ReverseFloat(w);
        l = ReverseFloat(l);
        */

        qDebug() << id << speed << x << y << w << l;
        QDrawer* pDrawer = new QDrawer(ptrPainterObstacle_->getWidgetWidth(), ptrPainterObstacle_->getWidgetHeight());
        listDrawers_.append(pDrawer);
        ptrPainterObstacle_->getDynamicObjects().append(new VehicleTrafficObject(*pDrawer, QPointF(x, y), w, l));
        //QDrawer* ptrDrawer = new QDrawer(ptrPainterObstacle_->getWidgetHeight(), ptrPainterObstacle_->getWidgetWeight());
        //ptrPainterObstacle_->getDynamicObjects().append(new VehicleTrafficObject(*ptrDrawer));
    }

}



QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    painterobstacle.cpp \
    qdrawer.cpp \
    qtpainterobstacle.cpp \
    roadmarkingstrafficobject.cpp \
    roadobjectpainter.cpp \
    screenwidget.cpp \
    trafficobject.cpp \
    vehicletrafficobject.cpp
    screenwidget.cpp
    qtpainterobstacle.cpp
    painterobstacle.cpp

HEADERS += \
    mainwindow.h \
    painterobstacle.h \
    qdrawer.h \
    qtpainterobstacle.h \
    roadmarkingstrafficobject.h \
    roadobjectpainter.h \
    screenwidget.h \
    trafficobject.h \
    vehicletrafficobject.h
    screenwidget.h
    qtpainterobstacle.h
    painterobstacle.h

LIBS += -lboost_system

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#-------------------------------------------------
#
# Project created by QtCreator 2015-03-22T02:11:57
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QOpenGls
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myglwidget.cpp

HEADERS  += mainwindow.h \
    myglwidget.h

FORMS    += mainwindow.ui

DISTFILES += \
    fragshader.frag \
    vertshader.vert

RESOURCES += \
    src.qrc

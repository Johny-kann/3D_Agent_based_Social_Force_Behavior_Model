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
    myglwidget.cpp \
    polygonwindow.cpp \
    traingle.cpp \
    glcontainer.cpp \
    secondwindow.cpp \
    texturemapping.cpp \
    eperiment.cpp \
    models.cpp \
    logics.cpp \
    datapoints.cpp

HEADERS  += mainwindow.h \
    myglwidget.h \
    polygonwindow.h \
    traingle.h \
    glcontainer.h \
    secondwindow.h \
    texturemapping.h \
    eperiment.h \
    models.h \
    logics.h \
    datapoints.h

FORMS    += mainwindow.ui \
    secondwindow.ui

DISTFILES += \
    fragshader.frag \
    vertshader.vert \
    lightingvertexshader.vsh \
    coloringvertexshader.vsh \
    coloringfragshader.fsh \
    lightingfragmentshader.fsh

RESOURCES += \
    src.qrc

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
    traingle.cpp \
    glcontainer.cpp \
    texturemapping.cpp \
    eperiment.cpp \
    models.cpp \
    logics.cpp \
    datapoints.cpp \
    openglwindow.cpp \
    texturemappingwindow.cpp \
    dummy.cpp

HEADERS  += mainwindow.h \
    myglwidget.h \
    traingle.h \
    glcontainer.h \
    texturemapping.h \
    eperiment.h \
    models.h \
    logics.h \
    datapoints.h \
    texturemappingwindow.h \
    openglwindow.h \
    dummy.h

FORMS    += mainwindow.ui \
    dummy.ui

DISTFILES += \
    fragshader.frag \
    vertshader.vert \
    lightingvertexshader.vsh \
    coloringvertexshader.vsh \
    coloringfragshader.fsh \
    lightingfragmentshader.fsh

RESOURCES += \
    src.qrc

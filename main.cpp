#include "mainwindow.h"
#include "myglwidget.h"
#include <QApplication>
#include "polygonwindow.h"
#include "traingle.h"
#include "glcontainer.h"

#include "texturemapping.h"
#include "secondwindow.h"
#include "eperiment.h"
#include "logics.h"
#include "eperiment.cpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
 //    QCoreApplication a(argc, argv);

//    QSurfaceFormat format;
//    format.setSamples(16);



 //  MainWindow ww;
//   SecondWindow ww;
    TextureMapping ww;
 //   ww.setAnimating(true);
  //  ww.renderLater();
 //   MyGLWidget ww;
 //   PolygonWindow ww;
 //   Traingle ww;
//    GLContainer ww;
 //   ww.setFormat(format);
    ww.show();

//    qDebug()<<Formula::gaussianFunction(2,0);

  //  Eperiment epr;
//    test tt;



    return a.exec();
}





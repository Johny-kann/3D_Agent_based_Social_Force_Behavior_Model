#include "mainwindow.h"
#include "myglwidget.h"
#include <QApplication>

#include "traingle.h"
#include "glcontainer.h"

#include "texturemapping.h"
#include "texturemappingwindow.h"

#include "eperiment.h"
#include "logics.h"
#include "eperiment.cpp"
#include "datapoints.h"



int main(int argc, char *argv[])
{
 //   QApplication app(argc, argv);
 //    QCoreApplication a(argc, argv);

//    QSurfaceFormat format;
//    format.setSamples(16);



 //  MainWindow ww;
//   SecondWindow ww;
 //   TextureMapping ww;
 //   ww.setAnimating(true);
  //  ww.renderLater();
 //   MyGLWidget ww;
 //   PolygonWindow ww;
 //   Traingle ww;
//    GLContainer ww;
 //   ww.setFormat(format);
//    ww.show();

//    qDebug()<<Formula::gaussianFunction(2,0);

  //  Eperiment epr;
//    test tt;


    QGuiApplication app(argc, argv);
/*
    QSurfaceFormat format;
    format.setSamples(16);

    TextureMappingWindow window;
    window.setFormat(format);
    window.show();
    window.setAnimating(true);
*/
  //  CubePoints cube1;

    LogicalClass::addHurdles(*(new World()),3,3,3,"fdjkfjds");

    return app.exec();
  //  return 0;
}





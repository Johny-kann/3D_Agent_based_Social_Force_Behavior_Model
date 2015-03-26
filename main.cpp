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
#include "dummy.h"



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


    World world;

    Hurdles hh;

    hh.setOpaqueDistance(2);
    hh.setRotate(0.0,0.0,0.0);
    hh.setStrength(3.0);
    hh.setTextureImage(constants::HURDLE_IMAGE);
    hh.setTranslate(0.0,0.0,-2.0);

    Hurdles hh2;

    hh2.setOpaqueDistance(2);
    hh2.setRotate(0.0,0.0,0.0);
    hh2.setStrength(3.0);
    hh2.setTextureImage(constants::HURDLE_IMAGE);
    hh2.setTranslate(3.0,0.0,-2.0);

    Hurdles hh3;

    hh3.setOpaqueDistance(2);
    hh3.setRotate(0.0,0.0,0.0);
    hh3.setStrength(3.0);
    hh3.setTextureImage(constants::HURDLE_IMAGE);
    hh3.setTranslate(-3.0,0.0,0.0);

    world.addHurdles(hh);
    world.addHurdles(hh2);
    world.addHurdles(hh3);



    QGuiApplication app(argc, argv);
 //   QApplication app(argc, argv);

    QSurfaceFormat format;
    format.setSamples(16);

    TextureMappingWindow window;
    window.setWorld(world);
    window.setFormat(format);
    window.show();
    window.setAnimating(true);

  //  CubePoints cube1;

  //  LogicalClass::addHurdles(*(new World()),3,3,3,"fdjkfjds");

  //  Dummy dd;
  //  dd.show();
    qDebug()<<Formula::randomNumber(50);


    return app.exec();
  //  return 0;
}





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
#include "controllers.h"



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


//    World world;

  /*  Hurdles hh;

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

*/
      QGuiApplication app(argc, argv);


  //  Camera *camera = new Camera(
  //              0.0,0.0,0.0,0.0,0.0,0.0,5.5);

    MainController controller;
    controller.initializeWorld();

    QSurfaceFormat format;
    format.setSamples(16);

    TextureMappingWindow window;
    window.setWorld(controller.getWorld());
    window.setFormat(format);
    window.show();
    window.setAnimating(true);

    controller.showScreen();

  //  CubePoints cube1;

  //  LogicalClass::addHurdles(*(new World()),3,3,3,"fdjkfjds");

  //  Dummy dd;
  //  dd.show();
  //  qDebug()<<Formula::randomNumber(50);

    World w;

    Hurdles h1;
    Hurdles h2;

    w.addHurdles(h1);
    w.addHurdles(h2);


    w.getHurdlesList().operator [](0).setTranslate(1.1,1.1,1.1);

    qDebug()<<w.getHurdlesList().operator [](0).getTransPos();
    return app.exec();
  //  return 0;
}





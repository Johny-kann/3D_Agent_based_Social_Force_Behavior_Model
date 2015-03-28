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
    window.setController(&controller);
    window.setWorld(&controller.getWorld());
    window.setFormat(format);
    window.show();
    window.setAnimating(true);


//    controller.showScreen();

  //  Hurdles hh;
     Hurdles hh2;
     hh2.setTranslate(1.0,0.0,-3.0);

     Movers mm;
    mm.setSpeed(.2);
    mm.setTranslate(0.0,0.0,0.0);
    mm.setDestinationPos(new QVector3D(50,0,50));

    Camera cc;
    Movers m2;
    cc.setTranslate(&m2.getTranslatePointer());
    qDebug()<<*cc.getTranslate();
//    m2.setTranslate();
    m2.setTranslate(
                2,3,4);
    qDebug()<<*cc.getTranslate();
    m2.setTranslate(*(new QVector3D(3,4,5)));
    m2.setTranslate(*(new QVector3D(3,4,5.5)));
    qDebug()<<*cc.getTranslate();
  //  controller.getWorld().addHurdles(hh);
    controller.getWorld().addHurdles(hh2);
     controller.getWorld().getCamera().setTranslate(mm.getCameraTransPos());
     qDebug()<<*(controller.getWorld().getCamera().getTranslate());

    controller.getWorld().addSources(mm);


 //   controller.calculateVelocity();

  //  qDebug()<<controller.getWorld().getSourceList().operator[](0).getTranslate();

    return app.exec();
  //  return 0;
}





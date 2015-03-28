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
      QGuiApplication app(argc, argv);

  //  QApplication app2(argc,argv);


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
  //   Hurdles hh2;
  //   hh2.setTranslate(1.0,0.0,-3.0);

     Movers mm;
      Movers mm2;
    mm.setSpeed(.5);
    mm2.setSpeed(0.5);
    mm.setTranslate(20.0,0.0,0.0);
    mm2.setTranslate(35.0,0.0,50.0);
    mm.setDestinationPos(new QVector3D(35,0,50));
    mm2.setDestinationPos(new QVector3D(0,0,0));

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
  //  controller.getWorld().addHurdles(hh2);
  //   controller.getWorld().getCamera().setTranslate(mm.getCameraTransPos());

     qDebug()<<*(controller.getWorld().getCamera().getTranslate());

    controller.getWorld().addSources(mm);
    controller.getWorld().addSources(mm2);
    controller.changeCamera(controller.centerLocation);

  /*  QLabel l;
      QPicture pi;
      QPainter p(&pi);

      p.setRenderHint(QPainter::Antialiasing);
      p.setPen(QPen(Qt::black, 12, Qt::DashDotLine, Qt::RoundCap));
      p.drawLine(0, 0, 200, 200);

      p.end(); // Don't forget this line!

      l.setPicture(pi);
      l.show();
*/

  //  app2.exec();
    return app.exec();
  //  return 0;
}





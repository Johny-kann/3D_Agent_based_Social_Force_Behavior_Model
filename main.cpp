#include "mainwindow.h"
#include "myglwidget.h"
#include <QApplication>
#include "polygonwindow.h"
#include "traingle.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

 /*   QSurfaceFormat format;
       format.setDepthBufferSize(24);
       format.setStencilBufferSize(8);
       format.setVersion(3, 2);
       format.setProfile(QSurfaceFormat::CoreProfile);
       QSurfaceFormat::setDefaultFormat(format);
*/

//    MainWindow w;

 //   MyGLWidget ww;
 //   PolygonWindow ww;
    Traingle ww;
 //   ww.setFormat(format);
    ww.show();

    return a.exec();
}

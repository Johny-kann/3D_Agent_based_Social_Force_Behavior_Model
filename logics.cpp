#include "logics.h"
#include <QtCore/qmath.h>
#include <QTime>
#include <QDebug>

double Formula::gaussianFunction(double sigma, double x)
{
    return exp(-(x*x)/(2*sigma*sigma));

}

double Formula::randomNumber(int max,int seed)
{
     qsrand(QTime::currentTime().msec()*seed);
    return (double)(qrand()%max);
}


void LogicClass::addHurdlesToWorld(World &world, int numberOfObjects, double opaqueDistance, double strength, QString str)
{
    for(int i=0; i<numberOfObjects; i++)
    {
     //   world.getHurdlesList().at(i).setTranslate(Formula::randomNumber(maxX),0,Formula::randomNumber(maxZ));
        Hurdles hurdle;

        hurdle.setOpaqueDistance(opaqueDistance);
        hurdle.setRotate(0.0,0.0,0.0);
      //  hurdle.setTranslate(Formula::randomNumber(50,i),0.0,Formula::randomNumber(50,-i));
        hurdle.setStrength(strength);
        hurdle.setTextureImage(str);

    //    qDebug()<<hurdle.getTransPos();

        world.addHurdles(hurdle);

    }

    addHurdlePosRandom(world,30);
}

void LogicClass::addHurdlePosRandom(World &world, int max)
{
    for(int i=0; i<world.getHurdlesList().size() ; i++)
    {
   //     new Hurdles().setTranslate(Formula::randomNumber(max),0.0,Formula::randomNumber(max));

        world.getHurdlesList().operator [](i).setTranslate(Formula::randomNumber(max,i),0.0,Formula::randomNumber(max,-i));
    }
}

#include "logics.h"
#include <QtCore/qmath.h>
#include <QTime>

double Formula::gaussianFunction(double sigma, double x)
{
    return exp(-(x*x)/(2*sigma*sigma));

}

double Formula::randomNumber(int max)
{
     qsrand(QTime::currentTime().msec());
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
        hurdle.setStrength(strength);
        hurdle.setTextureImage(str);

        world.addHurdles(hurdle);

    }
}

void LogicClass::addHurdlePosRandom(World &world, int max)
{
    for(int i=0; i<world.getHurdlesList().size() ; i++)
    {
   //     new Hurdles().setTranslate(Formula::randomNumber(max),0.0,Formula::randomNumber(max));

        world.getHurdlesList().operator [](i).setTranslate(Formula::randomNumber(max),0.0,Formula::randomNumber(max));
    }
}

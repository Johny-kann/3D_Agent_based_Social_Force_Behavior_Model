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


/*
void LogicalClass::addHurdlesRandomly(World world, int numberOfObjecs, int maxX, int maxZ)
{
    for(int i=0; i<numberOfObjecs; i++)
    {
   //   world.getHurdlesList().at(i);
    //    world.getHurdlesList().at(i).setTranslate(Formula::randomNumber(maxX),0,Formula::randomNumber(maxZ));


    }
}
*/
/*void LogicalClass::addHurdles(World world, int numberOfObjects, int opaqueDistance, int strength,QString str)
{
    for(int i=0; i<numberOfObjects; i++)
    {
     //   world.getHurdlesList().at(i).setTranslate(Formula::randomNumber(maxX),0,Formula::randomNumber(maxZ));
        Hurdles hurdle;
        hurdle.setCube(new CubePoints);
        hurdle.setOpaqueDistance(opaqueDistance);
        hurdle.setRotate(0.0,0.0,0.0);
        hurdle.setStrength(strength);
        hurdle.setTextureImage(str);

        world.addHurdles(hurdle);

    }

}
*/


void LogicalClass::addHurdlesRandomly(World world, int numberOfObjecs, int maxX, int maxZ)
{

}

void LogicalClass::addHurdles(World world, int numberOfObjects, int opaqueDistance, int strength, QString str)
{
    for(int i=0; i<numberOfObjects; i++)
    {
     //   world.getHurdlesList().at(i).setTranslate(Formula::randomNumber(maxX),0,Formula::randomNumber(maxZ));
    /*    Hurdles hurdle;
        hurdle.setCube(new CubePoints);
        hurdle.setOpaqueDistance(opaqueDistance);
        hurdle.setRotate(0.0,0.0,0.0);
        hurdle.setStrength(strength);
        hurdle.setTextureImage(str);
*/
        Movers *mm = new Movers();
      //  world.addHurdles(hurdle);

    }
}

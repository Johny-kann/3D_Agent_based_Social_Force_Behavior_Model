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

void LogicClass::calculateVelocity(World *world, Movers *movers)
{

    QVector3D vel1(movers->getTranslate());

    QVector3D vel2((*movers->getDestinationPos()));

    QVector3D difference((vel2-vel1));

    difference.normalize();

    movers->setVelocity(movers->getSpeed()*(
                            difference
                            ));

}


void LogicClass::calculateVelocity(World *world)
{
  //  qDebug()<<"Insides calc";
    for(int i = 0;i<world->getSourceList().size();i++)
    {
        Movers *mov = &world->getSourceList().operator [](i);
        if(mov->getMovingState())
        {
        calculateVelocity(world,mov);

        addForces(world,mov);
         mov->moveNextStep();

        }

    }
}

void LogicClass::moveSources(World *world)
{
    for(int i=0;i<world->getSourceList().size();i++)
    {
        world->getSourceList().operator [](i).startMoving();
    }
}

void LogicClass::stopSources(World *world)
{
    qDebug()<<"Stopped";
    for(int i=0;i<world->getSourceList().size();i++)
    {

        world->getSourceList().operator [](i).stopMoving();

    }
}

void LogicClass::addForces(World *world, Movers *movers)
{
    movers->setVelocity(constants::DEST_FORCE*movers->getVelocity());

    for(int i = 0;i<world->getHurdlesList().size();i++)
    {
        calculateIntermediateForce(movers,&world->getHurdlesList().operator [](i));
    }
}

void LogicClass::calculateIntermediateForce(Movers *movers, Hurdles *hurdle)
{
    double dist = movers->getTranslate().distanceToPoint(hurdle->getTranslate());
    dist = dist - (movers->getOpaqueDistance() + movers->getOpaqueDistance());

    if(dist>0)
    {
        QVector3D repelVector(hurdle->getTranslate()-movers->getTranslate());
        repelVector.normalize();

        double force = Formula::gaussianFunction(hurdle->getStrength(),dist);
        repelVector.operator *=(force);

        movers->setVelocity(movers->getVelocity()-repelVector);
    }else
    {
        qDebug()<<dist;
    }
}

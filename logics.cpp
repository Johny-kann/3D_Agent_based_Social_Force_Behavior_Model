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


void LogicClass::trigger(Movers *obj)
{
    QVector3D vel1(obj->getTranslate());

    QVector3D vel2((*obj->getDestinationPos()));

    QVector3D difference((vel2-vel1));

    difference.operator +=(QVector3D(1,0,-1));
    difference.normalize();

    obj->setVelocity(-obj->getSpeed()/20*(
                            difference
                            ));
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

 //   addHurdlePosRandom(world,30);
    addFixedPoints(world,numberOfObjects);

}

void LogicClass::addHurdlePosRandom(World &world, int max)
{
    for(int i=0; i<world.getHurdlesList().size() ; i++)
    {
   //     new Hurdles().setTranslate(Formula::randomNumber(max),0.0,Formula::randomNumber(max));

        world.getHurdlesList().operator [](i).setTranslate(Formula::randomNumber(max,i),0.0,Formula::randomNumber(max,-i));
    }
}

void LogicClass::addFixedPoints(World &world, int numberOfObjects)
{
    double HURDLE_POINTS[][2] = {{3.0,3.0},{6.0,2.0},{10.0,7.0},{25.0,6.0},{32.0,20.0},{23.0,20.0},{14.0,15.0},
                             {5.0,23.0},{15.0,30.0},{23.0,29.0},{28.0,31.0},{32.0,34.0},{38.0,39.0},{48.0,44.0},
                             {2.0,45.0},{12.0,48.0},{17.0,45.0},{25.0,46.0},{32.0,48.0},{39.0,47.0},{45,45.0}};
    for(int i=0;i<world.getHurdlesList().size();i++)
    {
        world.getHurdlesList().operator [](i).setTranslate(HURDLE_POINTS[i][0],0,HURDLE_POINTS[i][1]);
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

        mov->setVelocity(constants::DEST_FORCE*mov->getVelocity());
        addForces(world,mov);
        addForcesSource(world,mov,i);

        if(mov->getVelocity().length()<0.001)
        {
            qDebug()<<"Trigger";
            trigger(mov);
        }
         mov->moveNextStep();

    //     mov->syncTransHeads();

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
//    movers->setVelocity(constants::DEST_FORCE*movers->getVelocity());

    for(int i = 0;i<world->getHurdlesList().size();i++)
    {

        calculateIntermediateForce(movers,&world->getHurdlesList().operator [](i));

    }

}

void LogicClass::addForcesSource(World *world, Movers *movers, int currentMover)
{
    for(int i = 0;i<world->getSourceList().size();i++)
    {
        if(i!=currentMover)
        {
        calculateIntermediateForce(movers,&world->getSourceList().operator [](i));
        }

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

void LogicClass::calculateIntermediateForce(Movers *mover1, Movers *mover2)
{
    double dist = mover1->getTranslate().distanceToPoint(mover2->getTranslate());
    dist = dist - (mover1->getOpaqueDistance() + mover1->getOpaqueDistance());

    if(dist>0)
    {
        QVector3D repelVector(mover2->getTranslate()-mover1->getTranslate());
        repelVector.normalize();

        double force = Formula::gaussianFunction(mover2->getStrength(),dist);
        repelVector.operator *=(force);

        mover1->setVelocity(mover1->getVelocity()-repelVector);
    }else
    {
        qDebug()<<dist;
    }
}

void LogicClass::reverseRepel(QVector3D &repelVector)
{
    double x = repelVector.x();
    double z = repelVector.z();
    repelVector.setZ(x);
    repelVector.setX(z);
}

void LogicClass::attachCamera(World *world, int number)
{
    world->getCamera().setTranslate(world->getSourceList().operator [](number).getCameraTransPos());
}

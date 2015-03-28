#include "models.h"

#ifndef LOGICS
#define LOGICS

class Formula
{
public:
   static double gaussianFunction(double sigma,double x);
   static double randomNumber(int max, int seed);
};

class LogicClass
{
protected:
    static void trigger(Movers *obj);
  public:
    static void addHurdlesToWorld(World &world, int numberOfObjects, double opaqueDistance, double strength, QString str);
    static void addHurdlePosRandom(World &world,int max);
    static void addFixedPoints(World &world,int numberOfObjects);
    static void calculateVelocity(World *world, Movers *movers);
    static void calculateVelocity(World *world);
    static void moveSources(World *world);
    static void stopSources(World *world);
    static void addForces(World *world,Movers *movers);
    static void addForcesSource(World *world,Movers *movers,int currentMover);
    static void calculateIntermediateForce(Movers *movers,Hurdles *hurdle);
    static void calculateIntermediateForce(Movers *mover1,Movers *mover2);
    static void reverseRepel(QVector3D &repelVector);
    static void attachCamera(World *world, int number);
};

#endif // LOGICS


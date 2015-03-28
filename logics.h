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
  public:
    static void addHurdlesToWorld(World &world, int numberOfObjects, double opaqueDistance, double strength, QString str);
    static void addHurdlePosRandom(World &world,int max);
    static void calculateVelocity(World *world, Movers *movers);
    static void calculateVelocity(World *world);
};

#endif // LOGICS


#include "models.h"

#ifndef LOGICS
#define LOGICS

class Formula
{
public:
   static double gaussianFunction(double sigma,double x);
   static double randomNumber(int max);
};

class LogicClass
{
  public:
    static void addHurdlesToWorld(World &world, int numberOfObjects, double opaqueDistance, double strength, QString str);
    static void addHurdlePosRandom(World &world,int max);
};

#endif // LOGICS


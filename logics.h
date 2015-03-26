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
    static void addHurdlesToWorld(World &world, int numberOfObjects, int opaqueDistance, int strength, QString str);
    static void addHurdlePosRandom(World &world,int max);
};

#endif // LOGICS


#include "logics.h"
#include <QtCore/qmath.h>

double Formula::gaussianFunction(double sigma, double x)
{
    return exp(-(x*x)/(2*sigma*sigma));

}

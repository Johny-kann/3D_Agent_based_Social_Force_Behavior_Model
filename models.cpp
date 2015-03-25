#include "models.h"

Camera::Camera(double translateX, double translateY, double translateZ, double rotateX, double rotateY, double rotateZ,double distance)
{
    translate.setX(translateX);
    translate.setY(translateY);
    translate.setZ(translateZ);

    rotate.setX(rotateX);
    rotate.setY(rotateY);
    rotate.setZ(rotateZ);

    setDistance(distance);

}

void Camera::setTranslateX(double x){

   translate.setX(x);

}

void Camera::setTranslateY(double y){

    translate.setY(y);
}

void Camera::setTranslateZ(double z){

    translate.setZ(z);
}

void Camera::addTranslateX(double x)
{
    translate.setX(translate.x()+x);
 //   translateX+=x;
}

void Camera::addTranslateY(double y)
{
    translate.setY(translate.y()+y);
   // translateY+=y;
}

void Camera::addTranslateZ(double z)
{
    translate.setZ(translate.z()+z);
    //translateZ+=z;
}


void Camera::setRotateX(double x)
{
    rotate.setX(x);
}

void Camera::setRotateY(double y)
{
    rotate.setY(y);
}

void Camera::setRotateZ(double z)
{
    rotate.setZ(z);
}

void Camera::addRotateX(double x)
{
    rotate.setX(rotate.x()+x);
}

void Camera::addRotateY(double y)
{
    rotate.setY(rotate.y()+y);
}

void Camera::addRotateZ(double z)
{
    rotate.setZ(rotate.z()+z);
}

double Camera::getTranslateX()
{
    return translate.x();
}


double Camera::getTranslateY()
{
    return translate.y();
}

double Camera::getTranslateZ()
{
    return translate.z();
}

double Camera::getRotateX()
{
    return rotate.x();
}


double Camera::getRotateY()
{
    return rotate.y();
}

double Camera::getRotateZ()
{
    return rotate.z();
}

double Camera::getDistance()
{
    return distance;
}

void Camera::setDistance(double distance)
{
    this->distance = distance;
}

void Camera::addDistance(double distance)
{
    this->distance+=distance;
}

//-----------------------Source---------------------------

void Source::setTranslate(double transX, double transY, double transZ)
{
    this->translate.setX(transX);
    this->translate.setY(transY);
    this->translate.setZ(transZ);

}

void Source::setRotate(double rotX, double rotY, double rotZ)
{
    this->rotate.setX(rotX);
    this->rotate.setY(rotY);
    this->rotate.setZ(rotZ);
}

void Source::setDestinationPos(QVector3D *dest)
{
    this->destinationPos = dest;
}

void Source::setStrength(double strength)
{
    this->strength = strength;
}

void Source::setSpeed(double speed)
{
    this->speed = speed;
}

void Source::setOpaqueDistance(double opaqueDistance)
{
    this->opaqueDistance = opaqueDistance;
}

QVector3D Source::getTransPos()
{
    return this->translate;
}

QVector3D Source::getRotatePos()
{
    return this->rotate;
}

QVector3D Source::getDestination()
{
    return this->destinationPos;
}

QVector3D Source::getVelocity()
{
    return this->velocity;
}

double Source::getStrength()
{
   return this->strength;
}

double Source::getOpaqueDistance()
{
    return this->opaqueDistance;
}

double Source::getSpeed()
{
    return this->speed;
}

//-----------------------------------Hurdles-------------------





CubePoints *Hurdles::getCube() const
{
    return cube;
}

void Hurdles::setCube(CubePoints *value)
{
    cube = value;
}


void Hurdles::setTranslate(double transX, double transY, double transZ)
{
    this->translate.setX(transX);
    this->translate.setY(transY);
    this->translate.setZ(transZ);

}

void Hurdles::setRotate(double rotX, double rotY, double rotZ)
{
    this->rotate.setX(rotX);
    this->rotate.setY(rotY);
    this->rotate.setZ(rotZ);
}

void Hurdles::setStrength(double strength)
{
      this->strength = strength;
}

void Hurdles::setOpaqueDistance(double opaqueDistance)
{
   this->opaqueDistance =opaqueDistance;
}

QVector3D Hurdles::getTransPos()
{
    return this->translate;
}

QVector3D Hurdles::getRotatePos()
{
    return this->rotate;
}

double Hurdles::getStrength()
{
    return this->strength;
}

double Hurdles::getOpaqueDistance()
{
    return this->opaqueDistance;
}


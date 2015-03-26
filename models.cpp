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


double Movers::getStrength() const
{
    return strength;
}

void Movers::setStrength(double value)
{
    strength = value;
}

double Movers::getSpeed() const
{
    return speed;
}

void Movers::setSpeed(double value)
{
    speed = value;
}

double Movers::getOpaqueDistance() const
{
    return opaqueDistance;
}

void Movers::setOpaqueDistance(double value)
{
    opaqueDistance = value;
}

QVector3D *Movers::getDestinationPos() const
{
    return destinationPos;
}

void Movers::setDestinationPos(QVector3D *value)
{
    destinationPos = value;
}

QVector3D Movers::getVelocity() const
{
    return velocity;
}

void Movers::setVelocity(const QVector3D &value)
{
    velocity = value;
}

QVector3D Movers::getTranslate() const
{
    return translate;
}

void Movers::setTranslate(const QVector3D &value)
{
    translate = value;
}

QVector3D Movers::getRotate() const
{
    return rotate;
}

void Movers::setRotate(const QVector3D &value)
{
    rotate = value;
}

QString Movers::getTextureImage() const
{
    return textureImage;
}

void Movers::setTextureImage(const QString &value)
{
    textureImage = value;
}
Movers::Movers()
{
    this->setOpaqueDistance(0);
    //  this->setRotate();
}

Movers::Movers(double transx, double transy, double transz, double rotx, double roty, double rotz, double strength, double opaqueDistance)
{

}

void Movers::setTranslateAll(double transX, double transY, double transZ)
{
    this->translate.setX(transX);
    this->translate.setY(transY);
    this->translate.setZ(transZ);

}

void Movers::setRotateAll(double rotX, double rotY, double rotZ)
{
    this->rotate.setX(rotX);
    this->rotate.setY(rotY);
    this->rotate.setZ(rotZ);
}



//-----------------------------------Hurdles-------------------

/*
cubePoints *Hurdles::getCube() const
{
    return cube;
}

void Hurdles::setCube(CubePoints *value)
{
    cube = value;
}

*/

QString Hurdles::getTextureImage() const
{
    return textureImage;
}

void Hurdles::setTextureImage(const QString &value)
{
    textureImage = value;
}
Hurdles::Hurdles()
{
    this->translate.setX(0.0);
    this->translate.setY(0.0);
    this->translate.setZ(0.0);

    this->rotate.setX(0.0);
    this->rotate.setY(0.0);
    this->rotate.setZ(0.0);

    this->setStrength(0.0);
    this->setOpaqueDistance(0.0);
}

Hurdles::Hurdles(double transx, double transy, double transz, double rotx, double roty, double rotz, double strength, double opaqueDistance)
{
    this->translate.setX(transx);
    this->translate.setY(transy);
    this->translate.setZ(transz);

    this->rotate.setX(rotx);
    this->rotate.setY(roty);
    this->rotate.setZ(rotz);

    this->setStrength(strength);
    this->setOpaqueDistance(opaqueDistance);
}

/*void Hurdles::setTranslate(double transX, double transY, double transZ)
{
    translate.setX(transX);
    translate.setY(transY);
    translate.setZ(transZ);
}
*/
void Hurdles::setTranslate(double transX, double transY, double transZ)
{
    translate.setX(transX);
    translate.setY(transY);
    translate.setZ(transZ);

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


QList<Hurdles> World::getHurdlesList() const
{
    return hurdlesList;
}

void World::setHurdlesList(const QList<Hurdles> &value)
{
    hurdlesList = value;
}


void World::addHurdles(const Hurdles &hurdle)
{
    this->hurdlesList.append(hurdle);
  //  this->getHurdlesList().append(hurdle);
}

void World::addSources(const Movers &source)
{
    this->sourceList.append(source);

}

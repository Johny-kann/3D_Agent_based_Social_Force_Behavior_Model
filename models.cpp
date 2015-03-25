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

#include "models.h"

Camera::Camera(double translateX, double translateY, double translateZ, double rotateX, double rotateY, double rotateZ)
{
    this->translateX = translateX;
    this->translateY = translateY;
    this->translateZ = translateZ;

    this->rotateX = rotateX;
    this->rotateY = rotateY;
    this->rotateZ = rotateZ;

}

void Camera::setTranslateX(double x){

    translateX = x;
}

void Camera::setTranslateY(double y){

    translateY = y;
}

void Camera::setTranslateZ(double z){

    translateZ = z;
}

void Camera::addTranslateX(double x)
{
    translateX+=x;
}

void Camera::addTranslateY(double y)
{
    translateY+=y;
}

void Camera::addTranslateZ(double z)
{
    translateZ+=z;
}


void Camera::setRotateX(double x)
{
    rotateX = x;
}

void Camera::setRotateY(double y)
{
    rotateY = y;
}

void Camera::setRotateZ(double z)
{
    rotateZ = z;
}

void Camera::addRotateX(double x)
{
    rotateX+=x;
}

void Camera::addRotateY(double y)
{
    rotateY+=y;
}

void Camera::addRotateZ(double z)
{
    rotateZ+=z;
}

double Camera::getTranslateX()
{
    return translateX;
}


double Camera::getTranslateY()
{
    return translateY;
}

double Camera::getTranslateZ()
{
    return translateZ;
}

double Camera::getRotateX()
{
    return rotateX;
}


double Camera::getRotateY()
{
    return rotateY;
}

double Camera::getRotateZ()
{
    return rotateZ;
}

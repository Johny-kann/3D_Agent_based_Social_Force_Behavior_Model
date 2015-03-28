#include "models.h"


QVector3D *Camera::getTranslate() const
{
    return translate;
}

void Camera::setTranslate(QVector3D *value)
{
    translate = value;
}
Camera::Camera(double translateX, double translateY, double translateZ, double rotateX, double rotateY, double rotateZ,double distance)
{
    translate = new QVector3D(translateX,translateY,translateZ);
 //   translate->setX(translateX);
 //   translate->setY(translateY);
 //   translate->setZ(translateZ);

    rotate.setX(rotateX);
    rotate.setY(rotateY);
    rotate.setZ(rotateZ);

    setDistance(distance);

}

Camera::Camera()
{
    translate = new QVector3D(0.0,0.0,0.0);
 //   translate->setX(0.0);

  //  translate->setY(0.0);

  //  translate->setZ(0.0);

    rotate.setX(0.0);
    rotate.setY(0.0);
    rotate.setZ(0.0);

    setDistance(2.5);
}

Camera::~Camera()
{

}

void Camera::setTranslateX(double x){

   translate->setX(x);

}

void Camera::setTranslateY(double y){

    translate->setY(y);
}

void Camera::setTranslateZ(double z){

    translate->setZ(z);
}

void Camera::addTranslateX(double x)
{
    translate->setX(translate->x()+x);
 //   translateX+=x;
}

void Camera::addTranslateY(double y)
{
    translate->setY(translate->y()+y);
   // translateY+=y;
}

void Camera::addTranslateZ(double z)
{
    translate->setZ(translate->z()+z);
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
    return translate->x();
}


double Camera::getTranslateY()
{
    return translate->y();
}

double Camera::getTranslateZ()
{
    return translate->z();
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

QVector3D &Movers::getTranslatePointer()
{
    return this->translate;
}

void Movers::moveNextStep()
{
    this->translate.operator +=(this->velocity);
}

void Movers::startMoving()
{
    this->move = true;
}

void Movers::stopMoving()
{
    this->move = false;
}

bool Movers::getMovingState() const
{
    return this->move;
}


Movers::Movers()
{
    this->translate.setX(0.0);
    this->translate.setY(0.0);
    this->translate.setZ(0.0);

    this->rotate.setX(0.0);
    this->rotate.setY(0.0);
    this->rotate.setZ(0.0);

    this->setStrength(0.0);
    this->setOpaqueDistance(0.0);
    this->setTextureImage(constants::SOURCE_IMAGE);
 //   this->setOpaqueDistance(0);
    //  this->setRotate();

    this->velocity.setX(0.0);
    this->velocity.setY(0.0);
    this->velocity.setZ(0.0);
    this->stopMoving();
}

Movers::Movers(double transx, double transy, double transz, double rotx, double roty, double rotz, double strength, double opaqueDistance,
               QVector3D *dest)
{
    this->setTranslate(transx,transy,transz);
    this->setRotate(rotx,roty,rotz);
    this->setStrength(strength);
    this->setOpaqueDistance(opaqueDistance);

    this->setTextureImage(constants::SOURCE_IMAGE);

    this->destinationPos = dest;
    this->speed = 0;

    this->velocity.setX(0.0);
    this->velocity.setY(0.0);
    this->velocity.setZ(0.0);
    this->stopMoving();

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
/*

QString Hurdles::getTextureImage() const
{
    return textureImage;
}

void Hurdles::setTextureImage(const QString &value)
{
    textureImage = value;
}

*/
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
    this->setTextureImage(constants::HURDLE_IMAGE);
}

Hurdles::Hurdles(double transx, double transy, double transz, double rotx, double roty, double rotz, double strength, double opaqueDistance)
{


    this->setTranslate(transx,transy,transz);
    this->setRotate(rotx,roty,rotz);
    this->setStrength(strength);
    this->setOpaqueDistance(opaqueDistance);

    this->setTextureImage(constants::HURDLE_IMAGE);

}

/*void Hurdles::setTranslate(double transX, double transY, double transZ)
{
    translate.setX(transX);
    translate.setY(transY);
    translate.setZ(transZ);
}

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
*/
void Hurdles::setStrength(double strength)
{
      this->strength = strength;
}

void Hurdles::setOpaqueDistance(double opaqueDistance)
{
   this->opaqueDistance =opaqueDistance;
}

/*
QVector3D Hurdles::getTransPos()
{
    return this->translate;
}

QVector3D Hurdles::getRotatePos()
{
    return this->rotate;
}
*/
double Hurdles::getStrength()
{
    return this->strength;
}

double Hurdles::getOpaqueDistance()
{
    return this->opaqueDistance;
}



QList<Movers> &World::getSourceList()
{
    return sourceList;
}

void World::setSourceList(const QList<Movers> &value)
{
    sourceList = value;
}

/*Camera &World::getCamera() const
{
    return camera;
}

void World::setCamera(const Camera &value)
{
    camera = value;
}
*/

Camera &World::getCamera()
{
    return camera;
}

void World::setCamera(const Camera &value)
{
    camera = value;
}


QVector3D &World::getCenterLocation()
{
    return centerLocation;
}

void World::setCenterLocation(const QVector3D &value)
{
    centerLocation = value;
}
QList<Hurdles> &World::getHurdlesList()
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


QVector3D Objects::getRotate()
{
    return rotate;
}

void Objects::setRotate(const QVector3D &value)
{
    rotate = value;
}

QString Objects::getTextureImage() const
{
    return textureImage;
}

void Objects::setTextureImage(const QString &value)
{
    textureImage = value;
}

void Objects::setTexture(GLuint *texture)
{
    this->m_texture[0] = texture[0];
    this->m_texture[1] = texture[1];
    this->m_texture[1] = texture[1];
}

GLuint *Objects::getTexture()
{
    return this->m_texture;
}

QVector3D *Objects::getCameraTransPos() const
{
    return cameraTransPos;
}

void Objects::setCameraTransPos(QVector3D *value)
{
    cameraTransPos = value;
}
Objects::Objects()
{
    this->setTranslate(0.0,0.0,0.0);
    this->setRotate(0.0,0.0,0.0);
    this->cameraTransPos = new QVector3D(0.0,0.0,0.0);
    this->syncTransHeads();
}

Objects::Objects(double transX, double transY, double transZ, double rotX, double rotY, double rotZ)
{
    this->setTranslate(transX,transY,transZ);
    this->setRotate(rotX,rotY,rotZ);
    this->cameraTransPos = new QVector3D(0.0,0.0,0.0);
    this->syncTransHeads();

}

void Objects::setTranslate(double transX, double transY, double transZ)
{
    this->translate.setX(transX);
    this->translate.setY(transY);
    this->translate.setZ(transZ);
}

void Objects::setRotate(double rotX, double rotY, double rotZ)
{
    this->rotate.setX(rotX);
    this->rotate.setY(rotY);
    this->rotate.setZ(rotZ);
}

void Objects::syncTransHeads()
{
    this->cameraTransPos->setX(this->translate.x());
    this->cameraTransPos->setY(this->translate.y());
    this->cameraTransPos->setZ(this->translate.z());
}

QVector3D Objects::getTranslate()
{
    return translate;
}

void Objects::setTranslate(const QVector3D &value)
{
    translate = value;
}

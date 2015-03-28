#include <QVector3D>
#include "datapoints.h"

#ifndef MODELS
#define MODELS

class Camera
{
private:

    QVector3D translate;

    QVector3D rotate;

    double distance;

public:
    Camera(double translateX,double translateY,double translateZ,double rotateX,double rotateY,double rotateZ,double distance);
    Camera();
    ~Camera();
    void setTranslateX(double x);
    void setTranslateY(double y);
    void setTranslateZ(double z);

    void addTranslateX(double x);
    void addTranslateY(double y);
    void addTranslateZ(double z);

    void setRotateX(double x);
    void setRotateY(double y);
    void setRotateZ(double z);

    void addRotateX(double x);
    void addRotateY(double y);
    void addRotateZ(double z);


    double getRotateX();
    double getRotateY();
    double getRotateZ();

    double getTranslateX();
    double getTranslateY();
    double getTranslateZ();

    void setDistance(double distance);
    double getDistance();

    void addDistance(double distance);

};

class Objects
{
protected:
    QVector3D translate;

    QVector3D rotate;

    QString textureImage;

     GLuint m_texture[3];

public:
    Objects();
    Objects(double transX,double transY,double transZ,double rotX,double rotY,double rotZ);
    void setTranslate(double transX,double transY,double transZ);
    void setRotate(double rotX,double rotY,double rotZ);

    QVector3D getTranslate();
    void setTranslate(const QVector3D &value);
    QVector3D getRotate();
    void setRotate(const QVector3D &value);
    QString getTextureImage() const;
    void setTextureImage(const QString &value);

    void setTexture(GLuint *texture);
    GLuint *getTexture();
};

class Hurdles : public Objects
{

private:

    double strength;

    double opaqueDistance;


public:

    Hurdles();

    Hurdles(double transx,double transy,double transz,double rotx,double roty,double rotz,double strength,double opaqueDistance);

 //   void setTranslate(double transX,double transY,double transZ);

 //   void setRotate(double rotX,double rotY,double rotZ);

    void setStrength(double strength);

    void setOpaqueDistance(double opaqueDistance);

 //   QVector3D getTransPos();

 //   QVector3D getRotatePos();

    double getStrength();

    double getOpaqueDistance();


   // CubePoints *getCube() const;
  //  void setCube(CubePoints *value);

 //   QString getTextureImage() const;
 //   void setTextureImage(const QString &value);
};

class Movers : public Objects
{

private:
     QVector3D velocity;

    QVector3D *destinationPos;

    double strength;

    double speed;

    double opaqueDistance;

public:

    Movers();

    Movers(double transx, double transy, double transz, double rotx, double roty, double rotz, double strength, double opaqueDistance, QVector3D *dest);

    double getStrength() const;
    void setStrength(double value);
    double getSpeed() const;
    void setSpeed(double value);
    double getOpaqueDistance() const;
    void setOpaqueDistance(double value);
    QVector3D *getDestinationPos() const;
    void setDestinationPos(QVector3D *value);
    QVector3D getVelocity() const;
    void setVelocity(const QVector3D &value);

    void moveNextStep();
};

class World
{

private:
    QList<Hurdles> hurdlesList;
    QList<Movers> sourceList;

public:
    QList<Hurdles> &getHurdlesList();
    void setHurdlesList(const QList<Hurdles> &value);

    void addHurdles(const Hurdles &hurdle);
    void addSources(const Movers &source);

    QList<Movers> &getSourceList();
    void setSourceList(const QList<Movers> &value);
};

#endif // MODELS


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

class Hurdles
{

private:
    QVector3D translate;

    QVector3D rotate;

    CubePoints *cube;

    QString textureImage;

    double strength;

    double opaqueDistance;


public:

    Hurdles();

    Hurdles(double transx,double transy,double transz,double rotx,double roty,double rotz,double strength,double opaqueDistance);

    void setTranslate(double transX,double transY,double transZ);

    void setRotate(double rotX,double rotY,double rotZ);

    void setStrength(double strength);

    void setOpaqueDistance(double opaqueDistance);

    QVector3D getTransPos();

    QVector3D getRotatePos();

    double getStrength();

    double getOpaqueDistance();


    CubePoints *getCube() const;
    void setCube(CubePoints *value);
    QString getTextureImage() const;
    void setTextureImage(const QString &value);
};

class Movers
{

private:
    QVector3D translate;

    QVector3D rotate;

    QVector3D velocity;

    QVector3D *destinationPos;

    QString textureImage;

    double strength;

    double speed;

    double opaqueDistance;

public:

    Movers();

    Movers(double transx,double transy,double transz,double rotx,double roty,double rotz,double strength,double opaqueDistance);

    void setTranslateAll(double transX,double transY,double transZ);

    void setRotateAll(double rotX,double rotY,double rotZ);



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
    QVector3D getTranslate() const;
    void setTranslate(const QVector3D &value);
    QVector3D getRotate() const;
    void setRotate(const QVector3D &value);
    QString getTextureImage() const;
    void setTextureImage(const QString &value);
};

class World
{

private:
    QList<Hurdles> hurdlesList;
    QList<Movers> sourceList;

public:
    QList<Hurdles> getHurdlesList() const;
    void setHurdlesList(const QList<Hurdles> &value);

    void addHurdles(const Hurdles &hurdle);
    void addSources(const Movers &source);

};

#endif // MODELS


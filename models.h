#include <QVector3D>

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
};

class Source
{

private:
    QVector3D translate;

    QVector3D rotate;

    QVector3D velocity;

    QVector3D *destinationPos;

    double strength;

    double speed;

    double opaqueDistance;

public:

    Source();

    Source()(double transx,double transy,double transz,double rotx,double roty,double rotz,double strength,double opaqueDistance);

    void setTranslate(double transX,double transY,double transZ);

    void setRotate(double rotX,double rotY,double rotZ);

    void setDestinationPos(QVector3D *dest);

    void setStrength(double strength);

    void setSpeed(double speed);

    void setOpaqueDistance(double opaqueDistance);

    QVector3D getTransPos();

    QVector3D getRotatePos();

    QVector3D getDestination();

    QVector3D getVelocity();

    double getStrength();

    double getOpaqueDistance();

    double getSpeed();

};


#endif // MODELS


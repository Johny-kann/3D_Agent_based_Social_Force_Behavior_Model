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

class hurdles
{

private:
    QVector3D translate;

    QVector3D rotate;



public:

};

#endif // MODELS


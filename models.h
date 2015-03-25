#ifndef MODELS
#define MODELS

class Camera
{
private:
    double translateX;
    double translateY;
    double translateZ;

    double rotateX;
    double rotateY;
    double rotateZ;

public:
    Camera(double translateX,double translateY,double translateZ,double rotateX,double rotateY,double rotateZ);
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

  /*  double getRotateX();
    double getRotateY();
    double getRotateZ();
    */

};

#endif // MODELS


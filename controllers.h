#include "models.h"
#include <QSurfaceFormat>
#include "openglwindow.h"
#include <QOpenGLFunctions>


#ifndef CONTROLLERS
#define CONTROLLERS

class MainController
{
public:
  //  Camera camera;
    World world;
    int cameraSourceNumber;
    bool cameraCenter;
public:
    enum cameraActions
    {
        nextSource,previousSource,centerLocation
    };
public:
    MainController();
    ~MainController();
    void initializeWorld();

    void showScreen();
    void calculateVelocity();
    void changeCamera(cameraActions value);

    World &getWorld();
    void setWorld(const World &value);
    void moveSourcesOn(bool value);


};

#endif // CONTROLLERS


#include "models.h"
#include <QSurfaceFormat>
#include "openglwindow.h"
#include <QOpenGLFunctions>


#ifndef CONTROLLERS
#define CONTROLLERS

class MainController
{
public:
    Camera camera;
    World world;

public:
    MainController();
    ~MainController();
    void initializeWorld();

    void showScreen();
    void calculateVelocity();

    World &getWorld();
    void setWorld(const World &value);
    void moveSourcesOn(bool value);
};

#endif // CONTROLLERS


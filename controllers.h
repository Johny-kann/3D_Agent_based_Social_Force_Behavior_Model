#include "models.h"
#include <QSurfaceFormat>
#include "texturemappingwindow.h"
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

    World &getWorld();
    void setWorld(const World &value);
};

#endif // CONTROLLERS


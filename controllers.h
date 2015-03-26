#include "controllers.h"
#include "models.h"


#ifndef CONTROLLERS
#define CONTROLLERS

class MainController
{
public:
    Camera camera;
    World world;

public:

    void initializeWorld();

    void showScreen();
};

#endif // CONTROLLERS


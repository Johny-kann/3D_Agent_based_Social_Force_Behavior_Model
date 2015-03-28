#include "controllers.h"
#include "logics.h"
#include "datapoints.h"


MainController::~MainController()
{

}




World &MainController::getWorld()
{
    return world;
}

void MainController::setWorld(const World &value)
{
    world = value;
}

void MainController::moveSourcesOn(bool value)
{
    if(value)
        LogicClass::moveSources(&world);
    else
        LogicClass::stopSources(&world);
}
MainController::MainController()
{
    //   camera( 0.0,0.0,0.0,0.0,0.0,0.0,5.5);
    //   this->camera = camera;
    cameraSourceNumber = 0;
    this->world.setCenterLocation(QVector3D(25,0,25));
    this->changeCamera(centerLocation);


}

void MainController::initializeWorld()
{
    LogicClass::addHurdlesToWorld(world,constants::NO_OF_OBJECTS,
                                  constants::HURDLE_OPAQUE_DISTANCE,
                                  constants::HURDLE_STRENGTH,constants::HURDLE_IMAGE);

  //  LogicClass::addHurdlePosRandom(world,50);

}



void MainController::showScreen()
{


}

void MainController::calculateVelocity()
{
    LogicClass::calculateVelocity(&this->world);

}

void MainController::changeCamera(cameraActions value)
{
    if(value == nextSource)
    {
        if(this->cameraSourceNumber<world.getSourceList().size()-1)
        {
            cameraSourceNumber++;
            LogicClass::attachCamera(&this->world,cameraSourceNumber);
        }else
        {
            cameraSourceNumber=0;
            LogicClass::attachCamera(&this->world,cameraSourceNumber);
        }
    }
    else if(value == previousSource)
    {
        if(this->cameraSourceNumber > 0)
        {cameraSourceNumber--;
            LogicClass::attachCamera(&this->world,cameraSourceNumber);
        }else
        {
            cameraSourceNumber = world.getSourceList().size()-1;
                        LogicClass::attachCamera(&this->world,cameraSourceNumber);
        }
    }
    else if(value == centerLocation)
    {
            world.getCamera().setTranslate(&world.getCenterLocation());
    }

}

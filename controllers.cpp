#include "controllers.h"
#include "logics.h"
#include "datapoints.h"


MainController::~MainController()
{

}




World MainController::getWorld() const
{
    return world;
}

void MainController::setWorld(const World &value)
{
    world = value;
}
MainController::MainController()
{
    //   camera( 0.0,0.0,0.0,0.0,0.0,0.0,5.5);
    //   this->camera = camera;


}

void MainController::initializeWorld()
{
    LogicClass::addHurdlesToWorld(world,constants::NO_OF_OBJECTS,
                                  constants::HURDLE_OPAQUE_DISTANCE,
                                  constants::HURDLE_STRENGTH,constants::HURDLE_IMAGE);

    LogicClass::addHurdlePosRandom(world,50);

}

void MainController::showScreen()
{


}

#include "controllers.h"
#include "logics.h"
#include "datapoints.h"


void MainController::initializeWorld()
{
    LogicClass::addHurdlesToWorld(world,constants.NO_OF_OBJECTS,
                                  constants.HURDLE_OPAQUE_DISTANCE,
                                  constants.HURDLE_STRENGTH,constants.HURDLE_IMAGE);

}

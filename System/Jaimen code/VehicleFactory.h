#ifndef VEHICLEFACTORY_H
#define VEHICLEFACTORY_H

#include "ArmyFactory.h"

class VehicleFactory : public ArmyFactory {
    VehicleFactory();
    ~VehicleFactory();
    Army* createVehicle(string type, double probability);
};

#endif

//SlAPPER
//dONT ADD THAT TO THE GITHUB
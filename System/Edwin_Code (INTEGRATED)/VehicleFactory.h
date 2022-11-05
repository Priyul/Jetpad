#ifndef VEHICLEFACTORY_H
#define VEHICLEFACTORY_H

#include "ArmyFactory.h"

class VehicleFactory : public ArmyFactory {
public:
    VehicleFactory();
    //~VehicleFactory();
    Army* create(string rank, double probability);
};

#endif
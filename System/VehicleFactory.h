#ifndef VEHICLEFACTORY_H
#define VEHICLEFACTORY_H

#include "ArmyFactory.h"

class VehicleFactory : public ArmyFactory {
public:
    /**
     * @brief Constructor
     * 
     */
    VehicleFactory();
    //~VehicleFactory();
    /**
     * @brief Create an object of type vehicle
     * 
     * @param rank 
     * @param probability 
     * @return ** Army* 
     */
    Army* create(string rank, double probability);
};

#endif
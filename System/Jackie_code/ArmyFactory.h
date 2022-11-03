#ifndef ARMYFACTORY_H
#define ARMYFACTORY_H

#include "Soldier.h"
#include "Vehicle.h"

class ArmyFactory  {
    public:
        ArmyFactory();
        ~ArmyFactory();

        virtual Army* create(string type, double probability) = 0;

    protected:
        int strategy; //howzit
        int totalTroops;
};
#endif
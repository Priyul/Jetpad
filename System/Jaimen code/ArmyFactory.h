#ifndef ARMYFACTORY_H
#define ARMYFACTORY_H

#include "Soldier.h"
#include "Vehicle.h"

class ArmyFactory  {
    public:
        ArmyFactory();
        ~ArmyFactory();

        virtual Soldier* createSoldier() = 0;
        virtual Vehicle* createVehicle() = 0;

    private:
        int strategy; //howzit
        int totalTroops;
};
#endif

//SlAPPER
//dONT ADD THAT TO THE GITHUB
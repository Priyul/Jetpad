#ifndef WARSTRATEGY_H
#define WARSTRATEGY_H

#include <iostream>
#include <vector>
#include "Army.h"
#include "Engine.h"

class WarStrategy{
public:
    virtual std::string handle(vector<Army*> &ourArmy, vector<Army*> &AIArmy, std::string playerAttackStrategy, std::string CPUDefenseStrategy, int noOfAttackingVehiclesToSend, int noOfAttackingMajorsToSend, int noOfAttackingSergeantsToSend, int noOfAttackingPrivatesToSend, Engine* engine) = 0;
};


#endif


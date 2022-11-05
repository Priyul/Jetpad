#ifndef WARSTRATEGY_H
#define WARSTRATEGY_H

#include <iostream>
#include <vector>

#include "Army.h"

using namespace std;

class WarStrategy{
public:
    virtual std::string handle(vector<Army*> &ourArmy, vector<Army*> &AIArmy, std::string playerAttackStrategy, std::string CPUDefenseStrategy, int noOfAttackingVehiclesToSend, int noOfAttackingMajorsToSend, int noOfAttackingSergeantsToSend, int noOfAttackingPrivatesToSend) = 0;
};


#endif


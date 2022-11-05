#ifndef DEFENDING_H
#define ATTACKING_H

#include "WarStrategy.h"

class Defending : public WarStrategy{
public:
    Defending();
    std::string handle(vector<Army*> &ourArmy, vector<Army*> &AIArmy, std::string playerAttackStrategy, std::string CPUDefenseStrategy, int noOfAttackingVehiclesToSend, int noOfAttackingMajorsToSend, int noOfAttackingSergeantsToSend, int noOfAttackingPrivatesToSend);
};

#endif
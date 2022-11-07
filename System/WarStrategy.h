#ifndef WARSTRATEGY_H
#define WARSTRATEGY_H

#include <iostream>
#include <vector>
#include "Army.h"
#include "Engine.h"

class WarStrategy{
public:
    /**
     * @brief Choosing a war strategy and simulating fight between two army objects
     * 
     * @param ourArmy 
     * @param AIArmy 
     * @param playerAttackStrategy 
     * @param CPUDefenseStrategy 
     * @param noOfAttackingVehiclesToSend 
     * @param noOfAttackingMajorsToSend 
     * @param noOfAttackingSergeantsToSend 
     * @param noOfAttackingPrivatesToSend 
     * @return ** std::string 
     */
    virtual std::string handle(vector<Army*> &ourArmy, vector<Army*> &AIArmy, std::string playerAttackStrategy, std::string CPUDefenseStrategy, int noOfAttackingVehiclesToSend, int noOfAttackingMajorsToSend, int noOfAttackingSergeantsToSend, int noOfAttackingPrivatesToSend, Engine* engine) = 0;
};


#endif


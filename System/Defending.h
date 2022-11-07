#ifndef DEFENDING_H
#define DEFENDING_H

#include "WarStrategy.h"

#include <cstdlib>
#include <random>
#include <ctime>

#include "Country.h"
// #include "Engine.h"

class Defending : public WarStrategy{
public:
    /**
     * @brief Construct a new Defending object
     * 
     */
    Defending();

     /** @brief Implement defending strategy
     * 
     * @param ourArmy
     * @param AIArmy
     * @param playerAttackStrategy
     * @param CPUDefenseStrategy
     * @param noOfAttackingVehiclesToSend
     * @param noOfAttackingMajorsToSend
     * @param noOfAttackingSergeantsToSend
     * @param noOfAttackingPrivatesToSend
     * @return string
     * 
    */
    std::string handle(vector<Army*> &ourArmy, vector<Army*> &AIArmy, std::string playerAttackStrategy, std::string CPUDefenseStrategy, int noOfAttackingVehiclesToSend, int noOfAttackingMajorsToSend, int noOfAttackingSergeantsToSend, int noOfAttackingPrivatesToSend, Engine* engine);

};

#endif
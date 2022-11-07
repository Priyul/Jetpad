#ifndef ATTACKING_H
#define ATTACKING_H

#include "WarStrategy.h"

#include <cstdlib>
#include <random>
#include <ctime>

#include "Country.h"
// #include "Engine.h"

class Attacking : public WarStrategy{
public:
    /**
     * @brief Construct a new Attacking object
     * 
     */
    Attacking();

    /**
     * @brief Implement attacking strategy
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
//option 1) send remaining army to country class (reset country vector ie: country->setVector(this->vector))
//option 2) return a vector<army>; vector<Army*> remArmy = america->landAttack.handle(); 
            //

            //vector<Army*> remArmy = america->landAttack.handle(?); 
            //
            
            /* (in handle())
                sendSignal(0);
                //0 = AI won; 1 = you won
            */

           
            //country->setVector(remArmy)
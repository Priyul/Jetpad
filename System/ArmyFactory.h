#ifndef ARMYFACTORY_H
#define ARMYFACTORY_H

#include "Soldier.h"
#include "Vehicle.h"

class ArmyFactory  {
    public:
        /**
         * @brief Construct a new Army Factory object
         * 
         */
        ArmyFactory();

        /**
         * @brief Destroy the Army Factory object
         * 
        */
        ~ArmyFactory();

        /**
         * @brief create a new soldier or vehicle object
         * 
         * @param type
         * @param rank
         * @param probability
         * @return Army*
        */
        virtual Army* create(string type, double probability) = 0;

    protected:
        int strategy; 
        int totalTroops;
};
#endif
#ifndef WARUTILITIESFACTORY_H
#define WARUTILITIESFACTORY_H

#include <iostream>
#include "Soldier.h"
using namespace std;

class WarUtilitiesFactory
{
    public:
        /**
         * @brief Create a Vehicle object
         * 
         * @return ** void 
         */
        virtual void createVehicle()=0;
        /**
         * @brief Create a Soldier object
         * 
         * @return ** Soldier* 
         */
        virtual Soldier* createSoldier()=0;
        /**
         * @brief Destructor
         * 
         */
        ~WarUtilitiesFactory();
};

class SoldierFactory: public WarUtilitiesFactory
{
    public:
        /**
         * @brief Create a Soldier object
         * 
         * @return ** Soldier* 
         */
        Soldier* createSoldier();
};

class VehicleFactory: public WarUtilitiesFactory
{
    public:
        //Vehicle* 
        /**
         * @brief Create a Vehicle object
         * 
         * @return ** void 
         */
        void createVehicle();
};




#endif
#ifndef WARUTILITIESFACTORY_H
#define WARUTILITIESFACTORY_H

#include <iostream>
#include "Soldier.h"
using namespace std;

class WarUtilitiesFactory
{
    public:
        virtual void createVehicle()=0;
        //void virtual createWeapon();
        virtual Soldier* createSoldier()=0;
        ~WarUtilitiesFactory();
};

class SoldierFactory: public WarUtilitiesFactory
{
    public:
        Soldier* createSoldier();
};

class VehicleFactory: public WarUtilitiesFactory
{
    public:
        //Vehicle* 
        void createVehicle();
};




#endif
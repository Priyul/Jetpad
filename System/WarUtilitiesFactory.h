#ifndef WARUTILITIESFACTORY_H
#define WARUTILITIESFACTORY_H

#include <iostream>
using namespace std;

class WarUtilitiesFactory
{
    public:
        void virtual createVehicle();
        //void virtual createWeapon();
        void virtual createSoldier();
        ~WarUtilitiesFactory();
};

class SoldierFactory: public WarUtilitiesFactory
{
    public:
        //Soldier* 
        void createSoldier();
};

class VehicleFactory: public WarUtilitiesFactory
{
    public:
       // Vehicle*// 
       void createVehicle();
};




#endif
#include <iostream>
#include "WarUtilitiesFactory.h"

using namespace std;

Soldier* SoldierFactory::createSoldier()
{
    string rank;
    cout<<"What rank is your soldier?"<<endl;
    cin>>rank;
    return new Soldier(rank);
}

//Vehicle*
 void VehicleFactory::createVehicle()
{
    //return new Vehicle();
}
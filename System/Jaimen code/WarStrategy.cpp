#include "WarStrategy.h"
#include <iostream>
using namespace std;

WarStrategy::WarStrategy()
{
    strategy = 0;
    troops = NULL;
    troopsLost = NULL;
    vehicle = NULL;
    vehicleLost = NULL;
}

WarStrategy::~WarStrategy()
{
    delete troops;
    delete troopsLost;
    delete vehicle;
    delete vehicleLost;
}

void WarStrategy::setStrategy(int s)
{
    strategy = s;
}

int WarStrategy::getStrategy()
{
    return strategy;
}

void WarStrategy::setTroops(int t)
{
    troops = new Soldier(t);
}

int WarStrategy::getTroops()
{
    return troops->getSoldiers();
}

void WarStrategy::setTroopsLost(int t)
{
    troopsLost = new Soldier(t);
}

int WarStrategy::getTroopsLost()
{
    return troopsLost->getSoldiers();
}

void WarStrategy::setVehicle(int v)
{
    vehicle = new Vehicle(v);
}

int WarStrategy::getVehicle()
{
    return vehicle->getVehicle();
}

void WarStrategy::setVehicleLost(int v)
{
    vehicleLost = new Vehicle(v);
}

int WarStrategy::getVehicleLost()
{
    return vehicleLost->getVehicle();
}
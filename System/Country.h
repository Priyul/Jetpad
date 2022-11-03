#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>
#include <vector>

using namespace std;

#include "Army.h"
#include "SoldierFactory.h"
#include "VehicleFactory.h"
//#include "ArmyFactory.h"

#include "Soldier.h"
#include "Vehicle.h"

using namespace std;

class Country {
public:
    Country(string name, double money); 
    ~Country();

    string getCountryName();
    double getMoney();

    vector<Army*> army;
    void buildArmy();
    void showArmy();
    vector<Army*> attack();
    vector<Army*> getArmy();

    void countNumberOfIndividualTroops(vector<Army*> ourArmy);
    // void soldierInput(int input);

    void setName(string name);
    void setMoney(double money);

    void setSoldierFactory(ArmyFactory* soldierFactory);
    void setVehicleFactory(ArmyFactory* vehicleFactory);
protected:



private:
    double money;
    string countryName;

    ArmyFactory* soldierFactory;
    ArmyFactory* vehicleFactory;

    int numberOfMajors;
    int numberOfSergeants;
    int numberOfPrivates;

    int numberOfTanks;
    int numberOfPlanes;
    int numberOfShips;
};

#endif
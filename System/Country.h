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
    Country();
    //Country(string name, double money); we dont need this anymore because the builder sorts everything out
    ~Country();

    string getCountryName();
    double getMoney();

    vector<Army*> army; //move to private eventually
    void buildArmy();
    void showArmy();
    vector<Army*> attack();
    vector<Army*> getArmy();
    void setArmy(int numPlanes, int numTanks, int numShips, int numMajors, int numPrivates, int numSergeants);

    void countNumberOfIndividualTroops(vector<Army*> ourArmy);
    // void soldierInput(int input);

    void setName(string name);
    void setMoney(double money);

    void setSoldierFactory(ArmyFactory* soldierFactory);
    void setVehicleFactory(ArmyFactory* vehicleFactory);

    int numberOfMajors;
    int numberOfSergeants;
    int numberOfPrivates;

    int numberOfTanks;
    int numberOfPlanes;
    int numberOfShips;

    bool isMainCountry;

    
protected:



private:
    double money;
    string countryName;

    ArmyFactory* soldierFactory;
    ArmyFactory* vehicleFactory;
};

#endif
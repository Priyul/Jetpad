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

#include "Route.h"

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
    string attack();
    vector<Army*> getArmy();

    void countNumberOfIndividualTroops(vector<Army*> ourArmy);
    // void soldierInput(int input);

    void setName(string name);
    void setMoney(double money);

    void setSoldierFactory(ArmyFactory* soldierFactory);
    void setVehicleFactory(ArmyFactory* vehicleFactory);

    //for adding transportation route to country:
    void addRoute();
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

    Transport* baseTransportRoute;
};

#endif
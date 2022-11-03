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

    void buildArmy();
    void showArmy();
    // void soldierInput(int input);
    
protected:



private:
    double money;
    string countryName;
    vector<Army*> army;
};

#endif
#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>
#include <vector>

#include "Army.h"

using namespace std;

class Country {
public:
    Country(string name, double money); 
    ~Country();

    string getCountryName();
    double getMoney();
    vector<Army> army;

    void buildArmy();
    void soldierInput(int input);
    
protected:



private:
    double money;
    string countryName;
};

#endif
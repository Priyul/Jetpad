#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include "Army.h"

class Vehicle : public Army {
public:
    Vehicle(string type, double probability);
    ~Vehicle();

private:
    string type;
    double probability;

    string getType();
    double getProbability();
    void setProbability(double p);
};


#endif

//SlAPPER
//dONT ADD THAT TO THE GITHUB
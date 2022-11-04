#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include "Army.h"

using namespace std;

class Vehicle : public Army {
public:
    Vehicle();
    Vehicle(string type, double probability);
    ~Vehicle();

    string getRank();
    string getType();

    double getProbability();
    void setProbability(double p);

    virtual Army* clone();
private:
    string type;
 
};


#endif
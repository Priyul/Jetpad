#ifndef ARMY_H
#define ARMY_H
#include "ArmyPrototype.h"
#include <string>
#include <iostream>
using namespace std;

class Army : public ArmyPrototype {
protected:
    double probability;
public:
    Army();
    ~Army();
    virtual string getRank() = 0; //return rank of soldier || type of plane
    virtual string getType() = 0;
    virtual double getProbability() = 0;
    virtual void setProbability(double p) = 0;
    virtual ArmyPrototype* clone();
};

#endif
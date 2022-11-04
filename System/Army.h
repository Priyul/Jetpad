#ifndef ARMY_H
#define ARMY_H

#include <iostream>

using namespace std;

class Army {
protected:
    double probability;
public:
    virtual string getRank() = 0; //return rank of soldier || type of plane
    virtual string getType() = 0;
    virtual double getProbability() = 0;
    virtual void setProbability(double p) = 0;

    virtual Army* clone() = 0;
};

#endif
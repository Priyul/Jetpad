#ifndef SOLDIER_H
#define SOLDIER_H
#include <iostream>

#include "Army.h"

using namespace std;

class Soldier : public Army {
public:
    Soldier();
    Soldier(string type, double probability);
    ~Soldier();

    string getRank();
    double getProbability();
    void setProbability(double p);
    string getType();

    virtual Army* clone();

private:
    string rank;

};

#endif
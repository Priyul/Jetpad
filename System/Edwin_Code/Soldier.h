#ifndef SOLDIER_H
#define SOLDIER_H
#include <string>
#include <iostream>
#include "Army.h"

using namespace std;

class Soldier : public Army {
public:
    Soldier();
    Soldier(string rank, double probability);
    Soldier(const Soldier& soldier)
    ~Soldier();

    string getRank();
    double getProbability();
    void setProbability(double p);
    string getType();
    ArmyPrototype* clone();

private:
    string rank;
};

#endif
#ifndef SOLDIER_H
#define SOLDIER_H
#include <iostream>

#include "Army.h"

using namespace std;

class Soldier : public Army {
public:
    Soldier(string rank);
    ~Soldier();

    string getRank();
    double getProbability();
    void setProbability(double p);

private:
    string rank;
    double probability;

};

#endif
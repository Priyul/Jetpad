#ifndef SOLDIER_H
#define SOLDIER_H
#include <iostream>

#include "Army.h"

using namespace std;

class Soldier : public Army {
public:
    Soldier();
    Soldier(string type, double probability, string rank);
    ~Soldier();

    string getRank();

protected:
    string rank;

};

#endif

//SlAPPER
//dONT ADD THAT TO THE GITHUB
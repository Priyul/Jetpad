#ifndef BUILDER_H
#define BUILDER_H

#include <string>
#include "tempCountry.h"

using namespace std;

class Builder {
public:
    virtual void buildName(string name) = 0;
    virtual void buildArmy() = 0;
    virtual void buildMoney(double money) = 0;

    virtual tempCountry* getCountry() = 0;
}; 

#endif
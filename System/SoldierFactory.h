#ifndef SOLDIERFACTORY_H
#define SOLDIERFACTORY_H

#include "ArmyFactory.h"

class SoldierFactory : public ArmyFactory {
public:
    SoldierFactory();
    //~SoldierFactory();
    Army* create(string rank, double probability);
};

#endif
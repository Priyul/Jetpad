#ifndef SOLDIERFACTORY_H
#define SOLDIERFACTORY_H

#include "ArmyFactory.h"

class SoldierFactory : public ArmyFactory {
    SoldierFactory();
    ~SoldierFactory();
    Army* createSoldier(string type, double probability, string rank);
};

#endif
//1213
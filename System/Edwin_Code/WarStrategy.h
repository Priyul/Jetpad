#ifndef WARSTRATEGY_H
#define WARSTRATEGY_H

#include <iostream>
#include <vector>
#include "Army.h"

class WarStrategy{
public:
    virtual void handle(vector<Army*> ourArmy, vector<Army*> AIArmy, std::string playerAttackStrategy, std::string CPUDefenseStrategy) = 0;
};


#endif

#ifndef LANDDEFENSE_H
#define LANDDEFENSE_H

#include "WarStrategy.h"

class LandDefense : public WarStrategy{
public:
    LandDefense();
    void handle(vector<Army*> ourArmy, vector<Army*> AIArmy); //player function to defend
};

#endif
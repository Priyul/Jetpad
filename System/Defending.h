#ifndef DEFENDING_H
#define DEFENDING_H

#include "WarStrategy.h"

class Defending: public WarStrategy
{
    public:
    // Virtual Functions
         //Types of Defenses
         virtual void LandDefense();
         virtual void AirDefense();
         virtual void SeaDefense();
};

#endif
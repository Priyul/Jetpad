#ifndef ATTACKING_H
#define ATTACKING_H

#include "WarStrategy.h"

class Attacking: public WarStrategy
{
    public:
        // Types of Attacks
         virtual void LandAttack();
         virtual void AirAttack();
         virtual void SeaAttack();
};
#endif
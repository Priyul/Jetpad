#ifndef LAND_ATTACK_H
#define LAND_ATTACK_H

#include "Attacking.h"

class LandAttack: public Attacking
{
    public:
        void landAttack();
        LandAttack handle();
        ~LandAttack();
};
#endif

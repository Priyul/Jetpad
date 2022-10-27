#ifndef LANDATTACK_H
#define LANDATTACK_H

#include "Attacking.h"

class LandAttack: public Attacking
{
    public:
        void landAttack();
        LandAttack handle();
        ~LandAttack();
};

#endif
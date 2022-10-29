#ifndef LAND_ATTACK_H
#define LAND_ATTACK_H

#include "Attacking.h"

class Land_Attack: public Attacking
{
    public:
        void LandAttack();
        Land_Attack();
        Land_Attack* handle();
        ~Land_Attack();
};

#endif
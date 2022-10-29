#ifndef AIR_ATTACK_H
#define AIR_ATTACK_H

#include "Attacking.h"

class Air_Attack: public Attacking
{
    public:
        void AirAttack();
        Air_Attack();
        Air_Attack* handle();
        ~Air_Attack();
};

#endif
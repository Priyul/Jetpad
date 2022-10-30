#ifndef SEA_ATTACK_H
#define SEA_ATTACK_H

#include "Attacking.h"

class SeaAttack: public Attacking
{
    public:
        void seaAttack();
        SeaAttack handle();
        ~SeaAttack();
};
#endif
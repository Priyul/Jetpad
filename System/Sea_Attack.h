#ifndef SEA_ATTACK_H
#define SEA_ATTACK_H

#include "Attacking.h"

class Sea_Attack: public Attacking
{
    public:
        void SeaAttack(); 
        Sea_Attack();
        Sea_Attack* handle();
        ~Sea_Attack();
};

#endif
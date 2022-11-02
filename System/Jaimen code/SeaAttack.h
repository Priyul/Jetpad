#ifndef SEAATTACK_H
#define SEAATTACK_H

#include "Attacking.h"

class SeaAttack: public Attacking
{
    public:
        SeaAttack();
        SeaAttack* handle();
        ~SeaAttack();
};

#endif
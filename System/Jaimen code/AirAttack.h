#ifndef AIRATTACK_H
#define AIRATTACK_H

#include "Attacking.h"

class AirAttack: public Attacking
{
    public:
        AirAttack();
        AirAttack* handle();
        ~AirAttack();
};

#endif
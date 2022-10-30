#ifndef ATTACKING_H
#define ATTACKING_H

#include "WarStrategy.h"

class Attacking: public WarStrategy
{

    public:
    // Getters
        string getBattleState();
    // Virtual Functions
        Attacking();
        ~Attacking();
};
#endif
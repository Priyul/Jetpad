#ifndef ATTACKING_H
#define ATTACKING_H

#include "WarStrategy.h"

class Attacking: public WarStrategy
{
    public:
        // Types of Attacks
        virtual void LandAttackHandle() = 0;
        virtual void AirAttackHandle() = 0;
        virtual void SeaAttackHandle() = 0;

        void LandDefenseHandle(){cout << "hi";};
        void AirDefenseHandle(){cout << "hi";};
        void SeaDefenseHandle(){cout << "hi;";};
};

#endif
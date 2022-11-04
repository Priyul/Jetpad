#ifndef DEFENDING_H
#define DEFENDING_H

#include "WarStrategy.h"

class Defending: public WarStrategy
{
    public:
    // Virtual Functions
        //Types of Defenses
        virtual void LandDefenseHandle();
        virtual void AirDefenseHandle(){};
        virtual void SeaDefenseHandle(){};

        void LandAttackHandle(){cout << "hi";};
        void AirAttackHandle(){cout << "hi";};
        void SeaAttackHandle(){cout << "hi";};
};

#endif
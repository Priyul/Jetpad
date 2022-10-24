#ifndef DEFENDING_H
#define DEFENDING_H

#include "WarStrategy.h"

class Defending: public WarStrategy
{
    public:
    // Getters
        string getBattleState();
    // Virtual Functions
        // Types of Attacks
        virtual void LandDefense();
        virtual void AirDefense();
        virtual void SeaDefense();
};

#endif
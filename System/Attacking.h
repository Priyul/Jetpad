#ifndef ATTACKING_H
#define ATTACKING_H

#include "WarStrategy.h"

class Attacking: public WarStrategy
{
    public:
    // Getters
        string getBattleState();
    // Virtual Functions
        // Types of Attacks
        virtual void LandAttack();
        virtual void AirAttack();
        virtual void SeaAttack();
        ~Attacking();
};

class LandAttack: public Attacking
{
    public:
        void landAttack();
        LandAttack handle();
        ~LandAttack();
};

class AirAttack: public Attacking
{
    public:
        void airAttack();
        AirAttack handle();
        ~AirAttack();
};

class SeaAttack: public Attacking
{
    public:
        void seaAttack();
        SeaAttack handle();
        ~SeaAttack();
};

#endif
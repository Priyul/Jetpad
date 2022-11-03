#ifndef WARSTRATEGY_H
#define WARSTRATEGY_H

#include <iostream>

#include "Army.h"
#include <vector>

#include <random>

using namespace std;

class WarStrategy
{
public:
    // Getters
        string getBattleState(){return BattleState;};
    // Virtual Functions
    // Types of Attacks
        virtual void LandAttackHandle()=0;
        virtual void AirAttackHandle()=0;
        virtual void SeaAttackHandle()=0;
    // Types of Defense
        virtual void LandDefenseHandle()=0;
        virtual void AirDefenseHandle()=0;
        virtual void seaDefenseHandle()=0;
    protected:
        string BattleState;
};
#endif
